#include "King.h"

King::King(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "King")
{

}

King::~King()
{

}

unsigned int King::move(char x_cordinate, int y_cordinate, Board borad)
{
	return 0;
}

bool King::check_leggal_movement(char x_cordinate, int y_cordinate) const
{
	return 0;
}