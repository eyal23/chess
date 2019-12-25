#include "Knight.h"

Knight::Knight(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Knight")
{

}

Knight::~Knight()
{

}

unsigned int Knight::move(char x_cordinate, int y_cordinate, Board borad)
{
	return 0;
}

bool Knight::check_leggal_movement(char x_cordiante, int y_cordinate) const
{
	return 0;
}