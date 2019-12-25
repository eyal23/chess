#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(char x_cordinate, int y_cordinate, bool color);
	~Knight();

	unsigned int move(char x_cordinate, int y_cordinate, Board borad) override;
private:
	bool check_leggal_movement(char x_cordiante, int y_cordinate) const override;
};

