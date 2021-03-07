#include <iostream>
#include <string>

#include "Board.hpp"
#include "Piece.hpp"

using namespace std;

// fuwu ^^ lessthan3

// promotion -> of white must setWhite(true) bc default white == false
// why are squareNum and pieceNum printf statements printing reverse order
// if king is checked and valid move is pawn promotion, delete, new, set pinned == true -- promote into pin

// figure out castle in moves ? - can castle if enemy piece targetting piece he walks on

// upon moving --> check if !hasMoved --> moved = true

// figure out moves only for checks

int check_board(Board);


int main() {

	Board game;
	// set pawns and knights to canMove = true - done
	game.draw_board();

	return 0;
}

int check_board(Board) {
	// return : 0 if continue - 1 if player 1 wins - 2 if player 2 wins - 3 if player 1 king in check - 4 if player 2 king in check - 5 if stalemate

	return 0;
}