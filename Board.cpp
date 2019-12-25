#include <iostream>
#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"
#define MAX 8

using std::string;

Board::Board()
{
	int runs = 0;
	string start_string = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1";

	for (int y = MAX - 1; y > -1; y--)
	{
		for (int x = 0; x < MAX; x++, runs++)
		{
			add_piece(start_string[runs], x, y);
		}
	}

	this->_current_color = start_string[runs] - 48;
}

Board::~Board()
{
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			delete this->_pieces[x][y];
		}
	}
}

string Board::move(string& user_msg)
{
	int* cordinates = convert_string(user_msg);

	if (check_my_color(cordinates[0], cordinates[1]))
	{
		return "2";
	}
	else if (check_destination(cordinates[2], cordinates[3]))
	{
		return "3";
	}
	else if (this->_pieces[cordinates[0]][cordinates[1]].)
	{

	}
}

int* Board::convert_string(string& user_str) const
{
	int cordinates[4] = { user_str[0] - 98, user_str[1] - 49, user_str[2] - 98, user_str[3] - 49 };

	return cordinates;
}

Piece* Board::get_piece(int x_cordinate, int y_cordinate) const
{
	return this->_pieces[x_cordinate][y_cordinate];
}

bool Board::get_current_color() const
{
	return this->_current_color;
}

void Board::switch_color()
{
	this->_current_color = !this->_current_color;
}

bool Board::check_chess() const
{
	int x = 0, y = 0;

	for (x = 0; x < 8; x++)
	{
		for (y = 0; y < 8; y++)
		{
			if (this->_pieces[x][y]->get_type() == "King" && this->_pieces[x][y]->get_color() == this->_current_color)
			{
				break;
			}
		}
	}

	return check_chess_diagonal(x, y, -1, -1) ||
		check_chess_diagonal(x, y, -1, 1) ||
		check_chess_diagonal(x, y, 1, -1) ||
		check_chess_diagonal(x, y, -1, 1) ||
		check_chess_straight(x, y, false, -1) ||
		check_chess_straight(x, y, false, 1) ||
		check_chess_straight(x, y, true, -1) ||
		check_chess_straight(x, y, true, 1);
}

bool Board::check_my_color(int x, int y)
{
	if (this->_pieces[x][y] == nullptr)
	{
		return true;
	}

	return this->_pieces[x][y]->get_color() != this->_current_color;
}

bool Board::check_destination(int x, int y)
{
	if (this->_pieces[x][y] == nullptr)
	{
		return false;
	}

	return this->_pieces[x][y]->get_color() == this->_current_color;
}

void Board::add_piece(char type, int x, int y)
{
	bool color = 0;

	if (type == 'k' || type == 'K')
	{
		if (type == 'K')
		{
			color = true;
		}
		this->_pieces[x][y] = new King(x, y, color);
	}
	else if (type == 'q' || type == 'Q')
	{
		if (type == 'Q')
		{
			color = true;
		}
		this->_pieces[x][y] = new Queen(x, y, color);
	}
	else if (type == 'r' || type == 'R')
	{
		if (type == 'R')
		{
			color = true;
		}
		this->_pieces[x][y] = new Rook(x, y, color);
	}
	else if (type == 'n' || type == 'N')
	{
		if (type == 'N')
		{
			color = true;
		}
		this->_pieces[x][y] = new Knight(x, y, color);
	}
	else if (type == 'b' || type == 'B')
	{
		if (type == 'B')
		{
			color = true;
		}
		this->_pieces[x][y] = new Bishop(x, y, color);
	}
	else if (type == 'p' || type == 'P')
	{
		if (type == 'P')
		{
			color = true;
		}
		this->_pieces[x][y] = new Pawn(x, y, color);
	}
}

bool Board::check_chess_diagonal(int king_x, int king_y, int x_factor, int y_factor) const
{
	int distance = NULL;
	int current_y = this->_pieces[king_x][king_y]->get_y_cordinate() + y_factor;
	int current_x = this->_pieces[king_x][king_y]->get_x_cordinate() + x_factor;

	for (distance = 1; current_x >= 'a' && current_x <= 'h' && current_y >= 1 && current_y <= 8; current_x += x_factor, current_y += y_factor, distance++)
	{
		Piece* current_piece = get_piece(current_x, current_y);

		if (current_piece != nullptr)
		{
			if (this->_pieces[king_x][king_y]->get_color() != current_piece->get_color())
			{
				return current_piece->get_type() == "Queen" ||
					current_piece->get_type() == "Bishop" ||
					current_piece->get_type() == "Pawn" && distance == 1 ||
					current_piece->get_type() == "King" && distance == 1;
			}
			else
			{
				break;
			}
		}
	}

	return false;
}

bool Board::check_chess_straight(int king_x, int king_y, bool x_y, int factor) const
{
	int distance = NULL;
	int current_y = this->_pieces[king_x][king_y]->get_y_cordinate();
	char current_x = this->_pieces[king_x][king_y]->get_x_cordinate();

	if (x_y)
	{
		current_y += factor;
	}
	else
	{
		current_x += factor;
	}

	while (current_x >= 'a' && current_x <= 'h' && current_y >= 1 && current_y <= 8)
	{
		Piece* current_piece = get_piece(current_x, current_y);

		if (current_piece != nullptr)
		{
			if (this->_pieces[king_x][king_y]->get_color() != current_piece->get_color())
			{
				if (current_piece->get_type() == "Queen" ||
					current_piece->get_type() == "Rook" ||
					current_piece->get_type() == "King" && distance == 1)
				{
					return true;
				}
			}
			else
			{
				break;
			}
		}

		if (x_y)
		{
			current_y += factor;
		}
		else
		{
			current_x += factor;
		}
	}

	return false;
}

/*bool Board::check_chess_knight(int king_index) const
{


	return false;
}*/