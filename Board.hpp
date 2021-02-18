#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include <string>
#include <vector>

#include "Piece.hpp"

using namespace std;

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
	  // player sizes can stay 16. if pawn promotes -> delete pawn + new queen same vector index
	  vector<Piece*> player1;
	  vector<Piece*> player2;
	  
};

#endif