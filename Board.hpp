#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include <string>
#include <vector>

#include "Piece.hpp"

using namespace std;

struct Square {
	Square() {}
	/*
	Square(char column_, unsigned int row_) {
		column = column_;
		row = row_;
	}
	*/
	~Square() {}
	
	char getColumn() { return column; };
	void setColumn(unsigned int column1) { column = column1; };
	unsigned int getRow() { return row; };
	void setRow(unsigned int row1) { row = row1; };
	Piece* getPiece() { return piece; }
	void setPiece(Piece* piece1) { piece = piece1; };

	string printSquare() {
		string print = "";
		if (column != 'i') { print += column; }
		else { print += ' '; }
		if (row != 9) { print += to_string(row); }
		else { print += ' '; }
		return print;
	}

	Piece* piece = nullptr;
	unsigned int row = 9; // 1 - 8 .. rank
	char column = 'i'; // a - h .. file
};

struct Move {

};

class Board {
  public:
	  // static const unsigned int PLAYER_SIZE = 16;
	  Board();
	  ~Board();
	  void draw_board();
	  void flip_board();
	  void draw_flip_board();
	  vector<Piece*> getPlayer1() { return player1; };
	  vector<Piece*> getPlayer2() { return player2; };

  private:
	  // create board of 64 squares
	  vector<Square> theBoard;

	  // player sizes can stay 16. if pawn promotes -> delete pawn + new queen same vector index
	  vector<Piece*> player1;
	  vector<Piece*> player2;
	  
};

#endif