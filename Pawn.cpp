#include "Pawn.h"

Pawn::Pawn(char x_cordinate, int y_cordinate, bool color):
	Piece(x_cordinate, y_cordinate, color, "Pawn")
{

}

Pawn::~Pawn()
{

}

unsigned int Pawn::move(char x_cordinate, int y_cordinate, Board borad)
{
	return 0;
}

bool Pawn::check_leggal_movement() const
{
	return 0;
}