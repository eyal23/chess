#include "Bishop.h"

Bishop::Bishop(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Bishop")
{

}

Bishop::~Bishop()
{

}

unsigned int Bishop::move(int dst_x, int dst_y, Board& borad)
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

bool Bishop::check_leggal_movement(int dst_x, int dst_y)
{
	int* differences = get_differences(dst_x, dst_y);

	return differences[0] != differences[1];
}