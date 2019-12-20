#pragma once

#include <iostream>
#include <vector>
#include "Piece.h"

using std::vector;

class Piece;

class Board
{
private:
	bool _current_color;
	vector<Piece*> _pieces;
public:
	Board();
	~Board();

	vector<Piece*> get_all_pieces() const;
	Piece* get_piece(char x_cordinate, int y_cordinate) const;
	bool get_current_color() const;
	void switch_color();
	void remove_piece(char x_cordinate, int y_cordinate);
	
	bool check_chess() const;
	bool check_mate() const;
private:
	void add_piece(const char type, const char x_cordinate, const int y_cordinate);
};