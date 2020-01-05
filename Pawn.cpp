#include "Pawn.h"

Pawn::Pawn(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Pawn")
{

}

Pawn::~Pawn()
{

}

/*
this method checks, if the way is leggal moves the
pawn in the "test" board  by returninig true or false

input:
	int dest_x - the next x position to go to
	int dest_y - the next y position to go to
	Board *board - the "test" board

output:
	bool parm that makes sure that the move action is ok or not,
	if so then moves the king
*/
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

/*
this method checks whather if the way that the player decided to move his
pawn is primted, if so then the method returns the new position

input:
	int dest_x - the next x position to go to
	int dest_y - the next y position to go to

output:
	the new position

*/
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