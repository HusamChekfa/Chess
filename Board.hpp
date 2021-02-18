#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include <string>

#include "Piece.hpp"

using namespace std;

class Board {
  public:
	  Board();
	  ~Board();
	  void draw_board();
	  Piece* getPlayer1();
	  Piece* getPlayer2();
  private:
	  Piece player1[16];
	  Piece player2[16];
};

#endif