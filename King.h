#pragma once

#include "Piece.h"

class King : public Piece
{
public:
	King(char x_cordinate, int y_cordinate, bool color);
	~King();

	unsigned int move(char x_cordinate, int y_cordinate, Board borad) override;
private:
	bool check_leggal_movement(char x_cordiante, int y_cordinate) const override;
};

