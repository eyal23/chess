#pragma once

#include <iostream>
#include <vector>
#include "Piece.h"

using std::string;

class Piece;

class Board
{
private:
	bool _current_color;
	Piece* _pieces[8][8];
public:
	Board();
	~Board();

	Piece* get_piece(int x_cordinate, int y_cordinate) const;
	bool get_current_color() const;
	void switch_color();
	
	string move(string& user_msg);
public:
	int* convert_string(string& user_str) const;

	bool check_my_color(int x_cordinate, int y_cordinate);
	bool check_destination(int x_cordinate, int y_cordinate);
	bool check_chess() const;

	void add_piece(char type, int x, int y);
	bool check_chess_diagonal(int king_x, int king_y, int x_factor, int y_factor) const;
	bool check_chess_straight(int king_x, int king_y, bool x_y, int factor) const;
	bool check_chess_knight(int king_x, int king_y) const;
};