#include "Rook.h"

Rook::Rook(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Rook")
{

}

Rook::~Rook()
{

}

/*
this method checks, if the way is leggal moves the
rook in the "test" board  by returninig true or false

input:
	int dest_x - the next x position to go to
	int dest_y - the next y position to go to
	Board *board - the "test" board

output:
	bool parm that makes sure that the move action is ok or not,
	if so then moves the rook
*/
bool Rook::move(int dst_x, int dst_y, Board* board)
{
	if (!check_leggal_movement(dst_x, dst_y))
	{
		int x_factor = 0, y_factor = 0, x = 0, y = 0;

		if (this->_x_cordinate - dst_x == 0)
		{
			if (this->_y_cordinate - dst_y < 0)
			{
				y_factor = 1;
			}
			else
			{
				y_factor = -1;
			}
		}
		else if (this->_x_cordinate - dst_x < 0)
		{
			x_factor = 1;
		}
		else
		{
			x_factor = -1;
		}

		for (x = this->_x_cordinate + x_factor, y = this->_y_cordinate + y_factor; x != dst_x || y != dst_y; x += x_factor, y += y_factor)
		{
			Piece* current_piece = board->get_piece(x, y);

			if (current_piece != nullptr)
			{
				return true;
			}
		}

		this->_x_cordinate = dst_x;
		this->_y_cordinate = dst_y;

		return false;
	}
	

	return true;
}

/*
this method checks whather if the way that the player decided to move his
rook is primted, if so then the method returns the new position

input:
	int dest_x - the next x position to go to
	int dest_y - the next y position to go to

output:
	the new position

*/
bool Rook::check_leggal_movement(int dst_x, int dst_y)
{
	int* differences = get_differences(dst_x, dst_y);

	if (differences[0] == 0 && differences[1] != 0)
	{
		return false;
	}
	else if (differences[0] != 0 && differences[1] == 0)
	{
		return false;
	}

	return true;
}