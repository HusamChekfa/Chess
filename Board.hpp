#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include <string>
#include <vector>

#include "Piece.hpp"

using namespace std;

struct Square {
	Piece* piece;
	unsigned int row; // 1 - 8 .. rank
	char column; // a - h .. file
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