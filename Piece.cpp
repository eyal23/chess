#include "Piece.h"

Piece::Piece(char x_cordinate, int y_cordinate, bool color, string type):
	_x_cordinate(x_cordinate), _y_cordinate(y_cordinate), _color(color), _type(type)
{
}

Piece::~Piece()
{
}

/*
this methood gets the cordinates of the x - position

input: none
output: the x position
*/
char Piece::get_x_cordinate() const
{
	return this->_x_cordinate;
}

/*
this methood gets the cordinates of the y - position

input: none
output: the y position
*/
unsigned int Piece::get_y_cordinate() const
{
	return this->_y_cordinate;
}

/*
this methood gets the type of the piece

input: none
output: the type of the piece
*/
string Piece::get_type() const
{
	return this->_type;
}

/*
this methood gets the color of the curr team (black or white)

input: none
output: 
	bool type color (true or false, as in black or white)
*/
bool Piece::get_color() const
{
	return this->_color;
}

/*
this methood checks if a jump over a certin pieceh had happend

input: 
	board *board - the "test" board

output: none

*/
bool Piece::check_jump_over_piece(Board& board) const
{
	return 0;
}

/*
this methood gets the cordinates of the x position

input: 
	char x_cordinate - the curr x position
	int y_cordinate -  the curr y position

output: 
	int type differences - the new pusition
*/
int* Piece::get_differences(char x_cordinate, int y_cordinate) const
{
	int differences[2] = { this->_x_cordinate - x_cordinate, this->_y_cordinate - y_cordinate };

	for (int runs = 0; runs < 2; runs++)
	{
		if (differences[runs] < 0)
		{
			differences[runs] *= -1;
		}
	}

	return differences;
}