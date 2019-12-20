#pragma once

#include <iostream>
#include "Board.h"

using std::string;

class Board;

class Piece
{
protected:
	char _x_cordinate;
	unsigned int _y_cordinate;
	bool _color;
	string _type;
public:
	Piece(char x_cordinate, int y_cordinate, bool color, string type);
	~Piece();

	virtual unsigned int move(char x_cordinate, int y_cordinate, Board borad) = 0;
protected: 
	bool check_my_color(Board& board) const;
	bool check_jump_over_piece(Board& board) const;
	bool check_out_of_board() const;
	bool check_chess(Board& board) const;
	bool check_no_movement() const;
	virtual bool check_leggal_movement() const = 0;
};