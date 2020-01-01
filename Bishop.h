#pragma once

#include "Piece.h"

class Bishop: public Piece
{
public:
	Bishop(char x_cordinate, int y_cordinate, bool color);
	~Bishop();

	bool move(int dst_x, int dst_y, Board* board) override;
private:
	bool check_leggal_movement(int dst_x, int dst_y) override;
};

