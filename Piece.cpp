#include "Piece.h"

Piece::Piece(char x_cordinate, int y_cordinate, bool color, string type):
	_x_cordinate(x_cordinate), _y_cordinate(y_cordinate), _color(color), _type(type)
{
}

Piece::~Piece()
{
}

char Piece::get_x_cordinate() const
{
	return this->_x_cordinate;
}

unsigned int Piece::get_y_cordinate() const
{
	return this->_y_cordinate;
}

string Piece::get_type() const
{
	return this->_type;
}

bool Piece::get_color() const
{
	return this->_color;
}

bool Piece::check_my_color(Board& board) const
{
	return 0;
}

bool Piece::check_jump_over_piece(Board& board) const
{
	return 0;
}

bool Piece::check_out_of_board() const
{
	return 0;
}

bool Piece::check_chess(Board& board) const
{
	return 0;
}

bool Piece::check_no_movement() const
{
	return 0;
}

int* Piece::get_differences(char x_cordinate, int y_cordinate) const
{
	int differences[2] = { this->_x_cordinate - x_cordinate, this->_y_cordinate - y_cordinate };

	for (int runs = 0; runs < 2; runs++)
	{
		if (differences[runs] < 0)
		{
			differences[runs] *= -1;
		}
	}

	return differences;
}