#include "King.h"

King::King(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "King")
{

}

King::~King()
{

}

unsigned int King::move(int dst_x, int dst_y, Board* borad)
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

bool King::check_leggal_movement(int dst_x, int dst_y)
{
	int* differences = get_differences(dst_x, dst_y);

	return differences[0] > 1 || differences[1] > 1;
}