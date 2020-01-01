#pragma once

#include "Piece.h"

class Rook: public Piece
{
public:
	Rook(char x_cordinate, int y_cordinate, bool color);
	~Rook();

	bool move(int dst_x, int dst_y, Board* board) override;
private:
	bool check_leggal_movement(int dst_x, int dst_y) override;
};

