#pragma once

#include "Piece.h"

class Pawn : public Piece
{
private:
	bool _is_first_movement;
public:
	Pawn(char x_cordinate, int y_cordinate, bool color);
	~Pawn();

	unsigned int move(char x_cordinate, int y_cordinate, Board borad) override;
private:
	bool check_leggal_movement(char x_cordiante, int y_cordinate) const override;
};

