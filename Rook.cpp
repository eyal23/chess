#include "Rook.h"

Rook::Rook(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Rook")
{

}

Rook::~Rook()
{

}

unsigned int Rook::move(int dst_x, int dst_y, Board& borad)
{
	if (!check_leggal_movement(dst_x, dst_y))
	{
		if (this->_x_cordinate)
		{
		}
		else if ()
		{
		}
		return false;
	}
	else
	{
		return true;
	}
}

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