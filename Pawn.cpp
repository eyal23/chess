#include "Pawn.h"

Pawn::Pawn(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Pawn")
{

}

Pawn::~Pawn()
{

}

bool Pawn::move(int dst_x, int dst_y, Board* board)
{
	if (!check_leggal_movement(dst_x, dst_y))
	{
		int* differences = get_differences(dst_x, dst_y);

		if (differences[0] == 0 && board->get_piece(dst_x, dst_y) != nullptr)
		{
			return true;
		}
		else if (differences[0] != 0 && board->get_piece(dst_x, dst_y) == nullptr)
		{
			return true;
		}

		this->_x_cordinate = dst_x;
		this->_y_cordinate = dst_y;

		return false;
	}
	else
	{
		return true;
	}
}

bool Pawn::check_leggal_movement(int dst_x, int dst_y)
{
	int* differences = get_differences(dst_x, dst_y);

	if (differences[0] == 0 || differences[0] == 1)
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