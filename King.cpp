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

bool King::check_leggal_movement() const
{
	return 0;
}