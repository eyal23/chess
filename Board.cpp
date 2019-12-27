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

char* Board::move(string& user_msg)
{
	int* cordinates = convert_string(user_msg);
	int src_x = cordinates[0], src_y = cordinates[1], dst_x = cordinates[2], dst_y = cordinates[3];
	Piece & src_piece = *this->_pieces[src_x][src_y], & dst_piece = *this->_pieces[dst_x][dst_y];

	if (check_my_color(src_x, src_y))
	{
		char return_value[2] = { '2', NULL };
		return return_value;
	}
	else if (check_destination(dst_x, dst_y))
	{
		char return_value[2] = { '3', NULL };
		return return_value;
	}
	else if (this->_pieces[src_x][src_y]->move(dst_x, dst_y, *this))
	{
		char return_value[2] = { '6', NULL };
		return return_value;
	}
	else if (this->check_chess())
	{
		this->_pieces[src_x][src_y] = &src_piece;
		this->_pieces[dst_x][dst_y] = &dst_piece;
		char return_value[2] = { '4', NULL };
		return return_value;
	}
	
	this->switch_color();

	if (this->check_chess())
	{
		char return_value[2] = { '1', NULL };
		return return_value;
	}
	else
	{
		char return_value[2] = { '0', NULL };
		return return_value;
	}
}

int* Board::convert_string(string& user_str) const
{
	int cordinates[4] = { user_str[0] - 97, user_str[1] - 49, user_str[2] - 97, user_str[3] - 49 };

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
	bool flag = false;

	for (x = 0; x < 8 && !flag; x++)
	{
		for (y = 0; y < 8; y++)
		{
			if (this->_pieces[x][y] != nullptr)
			{
				if (this->_pieces[x][y]->get_type() == "King" && this->_pieces[x][y]->get_color() == this->_current_color)
				{
					flag = true;
					break;
				}
			}
		}
	}

	x--;

	return check_chess_diagonal(x, y, -1, -1) ||
		check_chess_diagonal(x, y, -1, 1) ||
		check_chess_diagonal(x, y, 1, -1) ||
		check_chess_diagonal(x, y, 1, 1) ||
		check_chess_straight(x, y, false, -1) ||
		check_chess_straight(x, y, false, 1) ||
		check_chess_straight(x, y, true, -1) ||
		check_chess_straight(x, y, true, 1) ||
		check_chess_knight(x, y);
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
	else
	{
		this->_pieces[x][y] = nullptr;
	}
}

bool Board::check_chess_diagonal(int king_x, int king_y, int x_factor, int y_factor) const
{
	int distance = NULL;
	int y = king_y + y_factor;
	int x = king_x + x_factor;

	for (distance = 1; x > -1 && x < MAX && y > -1 && y < MAX; x += x_factor, y += y_factor, distance++)
	{
		Piece* current_piece = this->_pieces[x][y];

		if (current_piece != nullptr)
		{
			if (this->_pieces[king_x][king_y]->get_color() != current_piece->get_color())
			{
				if (current_piece->get_type() == "Queen" ||
					current_piece->get_type() == "Bishop" ||
					current_piece->get_type() == "Pawn" && distance == 1 ||
					current_piece->get_type() == "King" && distance == 1)
				{
					return true;
				}
				else
				{
					break;
				}
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
	int y = king_x;
	int x = king_x;

	if (x_y)
	{
		y += factor;
	}
	else
	{
		x += factor;
	}

	while (x > -1 && x < MAX && y > -1 && y < MAX)
	{
		Piece* current_piece = get_piece(x, y);

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
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}

		if (x_y)
		{
			y += factor;
		}
		else
		{
			x += factor;
		}
	}

	return false;
}

bool Board::check_chess_knight(int king_x, int king_y) const
{
	int runs1 = 0, runs2 = 0, runs3 = 0, kx = king_x, ky = king_y;
	int* temp = nullptr, * p1 = &kx, * p2 = &ky;

	for (runs1 = 0; runs1 < 2; runs1++)
	{
		for (runs2 = 0, *p1 -= 2; runs2 < 2; runs2++, *p1 += 4)
		{
			for (runs3 = 0, *p2 -= 1; runs3 < 2; runs3++, *p2 += 2)
			{
				if (*p1 > -1 && *p1 < MAX && *p2 > -1 && *p2 < MAX)
				{
					Piece* current_piece = nullptr;

					if (runs1)
					{
						current_piece = get_piece(*p2, *p1);
					}
					else
					{
						current_piece = get_piece(*p1, *p2);
					}

					if (current_piece != nullptr)
					{
						if (this->_pieces[king_x][king_y]->get_color() != current_piece->get_color() && current_piece->get_type() == "Knight")
						{
							return true;
						}
					}
				}
			}

			*p2 -= 3;
		}

		*p1 -= 6;

		temp = p1;
		p1 = p2;
		p2 = temp;
	}

	return false;
}