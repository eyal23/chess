#include "Rook.h"

Rook::Rook(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Rook")
{

}

Rook::~Rook()
{

}

unsigned int Rook::move(char x_cordinate, int y_cordinate, Board borad)
{
	return 0;
}

bool Rook::check_leggal_movement() const
{
	return 0;
}