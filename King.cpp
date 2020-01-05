#include "King.h"

King::King(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "King")
{

}

King::~King()
{

}

/*
this method checks, if the way is leggal moves the
king in the "test" board  by returninig true or false

input:
	int dest_x - the next x position to go to
	int dest_y - the next y position to go to
	Board *board - the "test" board

output:
	bool parm that makes sure that the move action is ok or not, 
	if so then moves the king
*/
bool King::move(int dst_x, int dst_y, Board* borad)
{
	if (!check_leggal_movement(dst_x, dst_y))
	{
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
king is primted, if so then the method returns the new position

input:
	int dest_x - the next x position to go to
	int dest_y - the next y position to go to

output:
	the new position

*/
bool King::check_leggal_movement(int dst_x, int dst_y)
{
	int* differences = get_differences(dst_x, dst_y);

	return differences[0] > 1 || differences[1] > 1;
}