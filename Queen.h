#pragma once

#include "Piece.h"

class Queen: public Piece
{
public:
	Queen(char x_cordinate, int y_cordinate, bool color);
	~Queen();

	unsigned int move(int dst_x, int dst_y, Board* board) override;
private:
	bool check_leggal_movement(int dst_x, int dst_y) override;
};