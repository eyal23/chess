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
			this->_pieces.erase(this->_pieces.begin() + runs);
			break;
		}
	}
}

bool Board::check_chess() const
{
	return 0;
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