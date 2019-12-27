#pragma once

#include "Piece.h"

class Queen: public Piece
{
public:
	Queen(char x_cordinate, int y_cordinate, bool color);
	~Queen();

	unsigned int move(char x_cordinate, int y_cordinate, Board& borad) override;
private:
	bool check_leggal_movement(char x_cordiante, int y_cordinate) const override;
};