#pragma once

#include "Piece.h"

class Rook: public Piece
{
public:
	Rook(char x_cordinate, int y_cordinate, bool color);
	~Rook();

	unsigned int move(char x_cordinate, int y_cordinate, Board borad) override;
private:
	bool check_leggal_movement() const override;
};

