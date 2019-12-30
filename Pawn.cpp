#include "Pawn.h"

Pawn::Pawn(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Pawn")
{

}

Pawn::~Pawn()
{

}

unsigned int Pawn::move(int dst_x, int dst_y, Board& borad)
{
	if (!check_leggal_movement(dst_x, dst_y))
	{
		/*
			YOUR CODE
		*/

		return false;
	}
	else
	{
		return true;
	}
}

bool Pawn::check_leggal_movement(int dst_x, int dst_y)
{
	if (dst_x - this->_x_cordinate == 0)
	{
		if (this->_color)
		{
			if (dst_y - this->_y_cordinate == 1)
			{
				this->_is_first_movement = false;
				return false;
			}
			else if (dst_y - this->_y_cordinate == 2 && this->_is_first_movement)
			{
				return false;
			}
		}
		else
		{
			if (this->_y_cordinate - dst_y == 1)
			{
				this->_is_first_movement = false;
				return false;
			}
			else if (this->_y_cordinate - dst_y == 2 && this->_is_first_movement)
			{
				return false;
			}
		}
	}

	return true;
}