#include "Queen.h"

Queen::Queen(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Queen")
{

}

Queen::~Queen()
{

}

unsigned int Queen::move(char x_cordinate, int y_cordinate, Board& borad)
{
	return 0;
}

bool Queen::check_leggal_movement(char x_cordiante, int y_cordinate) const
{
	return 0;
}