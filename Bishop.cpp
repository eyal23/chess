#include "Bishop.h"

Bishop::Bishop(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Bishop")
{

}

Bishop::~Bishop()
{

}

unsigned int Bishop::move(char x_cordinate, int y_cordinate, Board borad)
{
	return 0;
}

bool Bishop::check_leggal_movement() const
{
	return 0;
}