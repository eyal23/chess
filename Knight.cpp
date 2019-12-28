#include "Knight.h"

Knight::Knight(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Knight")
{

}

Knight::~Knight()
{

}

unsigned int Knight::move(int dst_x, int dst_y, Board& borad)
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

bool Knight::check_leggal_movement(int dst_x, int dst_y)
{
	int* differences = get_differences(dst_x, dst_y);

	return !(differences[0] == 1 && differences[1] == 2) ||
		!(differences[0] == 2 && differences[1] == 1);
}