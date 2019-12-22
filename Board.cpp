#include <iostream>
#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"

#define MAX_X 'h'
#define MAX_Y 8

using std::string;

Board::Board()
{
	int runs = 0;
	string start_string = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1";

	for (int current_y = MAX_Y; current_y > 0; current_y--)
	{
		for (char current_x = 'a'; current_x <= MAX_X; current_x++, runs++)
		{
			add_piece(start_string[runs], current_x, current_y);
		}
	}

	this->_current_color = start_string[runs] - 48;
}

Board::~Board()
{
}

vector<Piece*> Board::get_all_pieces() const
{
	return this->_pieces;
}

Piece* Board::get_piece(char x_cordinate, int y_cordinate) const
{
	for (int runs = 0; runs < this->_pieces.size(); runs++)
	{
		if (this->_pieces[runs]->get_x_cordinate() == x_cordinate && this->_pieces[runs]->get_y_cordinate() == y_cordinate)
		{
			return this->_pieces[runs];
		}
	}

	return nullptr;
}

bool Board::get_current_color() const
{
	return this->_current_color;
}

void Board::switch_color()
{
	if (this->_current_color)
	{
		this->_current_color = false;
	}
	else
	{
		this->_current_color = true;
	}
}

void Board::remove_piece(char x_cordinate, int y_cordinate)
{
	for (int runs = 0; runs < this->_pieces.size(); runs++)
	{
		if (this->_pieces[runs]->get_x_cordinate() == x_cordinate && this->_pieces[runs]->get_y_cordinate() == y_cordinate)
		{
			delete this->_pieces[runs];
			this->_pieces.erase(this->_pieces.begin() + runs);
			break;
		}
	}
}

bool Board::check_chess() const
{
	int king_index = NULL;

	for (king_index = 0; king_index < this->_pieces.size(); king_index++)
	{
		if (this->_pieces[king_index]->get_type() == "King" && this->_pieces[king_index]->get_color() == this->_current_color)
		{
			break;
		}
	}

	return check_chess_diagonal(king_index, -1, -1) ||
		check_chess_diagonal(king_index, -1, 1) ||
		check_chess_diagonal(king_index, 1, -1) ||
		check_chess_diagonal(king_index, -1, 1) ||
		check_chess_straight(king_index, false, -1) ||
		check_chess_straight(king_index, false, 1) ||
		check_chess_straight(king_index, true, -1) ||
		check_chess_straight(king_index, true, 1);
}

bool Board::check_mate() const
{
	return 0;
}

void Board::add_piece(char type, char x_cordinate, int y_cordinate)
{
	bool color = 0;

	if (type == 'k' || type == 'K')
	{
		if (type == 'K')
		{
			color = true;
		}
		this->_pieces.push_back(new King(x_cordinate, y_cordinate, color));
	}
	else if (type == 'q' || type == 'Q')
	{
		if (type == 'Q')
		{
			color = true;
		}
		this->_pieces.push_back(new Queen(x_cordinate, y_cordinate, color));
	}
	else if (type == 'r' || type == 'R')
	{
		if (type == 'R')
		{
			color = true;
		}
		this->_pieces.push_back(new Rook(x_cordinate, y_cordinate, color));
	}
	else if (type == 'n' || type == 'N')
	{
		if (type == 'N')
		{
			color = true;
		}
		this->_pieces.push_back(new Knight(x_cordinate, y_cordinate, color));
	}
	else if (type == 'b' || type == 'B')
	{
		if (type == 'B')
		{
			color = true;
		}
		this->_pieces.push_back(new Bishop(x_cordinate, y_cordinate, color));
	}
	else if (type == 'p' || type == 'P')
	{
		if (type == 'P')
		{
			color = true;
		}
		this->_pieces.push_back(new Pawn(x_cordinate, y_cordinate, color));
	}
}

bool Board::check_chess_diagonal(int king_index, int x_factor, int y_factor) const
{
	int distance = NULL;
	int current_y = this->_pieces[king_index]->get_y_cordinate() + y_factor;
	char current_x = this->_pieces[king_index]->get_x_cordinate() + x_factor;

	for (distance = 1; current_x >= 'a' && current_x <= 'h' && current_x >= 1 && current_x <= 8; current_x += x_factor, current_y += y_factor, distance++)
	{
		Piece* current_piece = get_piece(current_x, current_y);

		if (current_piece != nullptr)
		{
			if (this->_pieces[king_index]->get_color() != current_piece->get_color())
			{
				if (current_piece->get_type() == "Queen" ||
					current_piece->get_type() == "Bishop" ||
					current_piece->get_type() == "Pawn" && distance == 1 ||
					current_piece->get_type() == "King" && distance == 1)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Board::check_chess_straight(int king_index, bool x_y, int factor) const
{
	int distance = NULL;
	int current_y = this->_pieces[king_index]->get_y_cordinate();
	char current_x = this->_pieces[king_index]->get_x_cordinate();

	if (x_y)
	{
		current_y += factor;
	}
	else
	{
		current_y += factor;
	}

	while (current_x >= 'a' && current_x <= 'h' && current_x >= 1 && current_x <= 8)
	{
		Piece* current_piece = get_piece(current_x, current_y);

		if (current_piece != nullptr)
		{
			if (this->_pieces[king_index]->get_color() != current_piece->get_color())
			{
				if (current_piece->get_type() == "Queen" ||
					current_piece->get_type() == "Rook" ||
					current_piece->get_type() == "King" && distance == 1)
				{
					return true;
				}
			}
		}

		if (x_y)
		{
			current_y += factor;
		}
		else
		{
			current_y += factor;
		}
	}

	return false;
}