#pragma once

#include "Piece.h"

class Pawn : public Piece
{
private:
	bool _is_first_movement;
public:
	Pawn(char x_cordinate, int y_cordinate, bool color);
	~Pawn();

	unsigned int move(int dst_x, int dst_y, Board* borad) override;
private:
	bool check_leggal_movement(int dst_x, int dst_y) override;
};

