#pragma once

#include <iostream>
#include "Board.h"

using std::string;

class Board;

class Piece
{
protected:
	int _x_cordinate;
	int _y_cordinate;
	bool _color;
	string _type;
public:
	Piece(char x_cordinate, int y_cordinate, bool color, string type);
	~Piece();

	char get_x_cordinate() const;
	unsigned int get_y_cordinate() const;
	string get_type() const;
	bool get_color() const;

	virtual unsigned int move(int dst_x, int dst_y, Board* board) = 0;
protected: 
	bool check_jump_over_piece(Board& board) const;
	virtual bool check_leggal_movement(int dst_x, int dst_y) = 0;

	int* get_differences(char x_cordiante, int y_cordinate) const;
};