#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(char x_cordinate, int y_cordinate, bool color);
	~Knight();

	unsigned int move(int dst_x, int dst_y, Board* borad) override;
private:
	bool check_leggal_movement(int dst_x, int dst_y) override;
};

