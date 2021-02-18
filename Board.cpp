#include <iostream>
#include <string>
#include <vector>

#include "Board.hpp"
#include "Piece.hpp"

using namespace std;

Board::Board() {
	//player1.resize(16);
	//player2.resize(16);
	//player1.at(0) = Pawn();

	player1.resize(16);
	player2.resize(16);
	for (unsigned int i = 0; i < 8; ++i) {
		player1.at(i) = new Pawn;
		player2.at(i) = new Pawn;
	}
	for (unsigned int i = 8; i < 10; ++i) {
		player1.at(i) = new Knight;
		player2.at(i) = new Knight;
	}
	for (unsigned int i = 10; i < 12; ++i) {
		player1.at(i) = new Bishop;
		player2.at(i) = new Bishop;
	}
	for (unsigned int i = 12; i < 14; ++i) {
		player1.at(i) = new Rook;
		player2.at(i) = new Rook;
	}

	player1.at(14) = new Queen;
	player2.at(14) = new Queen;
	player1.at(15) = new King;
	player2.at(15) = new King;

	// set bools and chnames
};

Board::~Board() {

};

void Board::draw_board() {
	for (unsigned int i = 0; i < 47; ++i) {
		if ((i + 1) % 6 == 0) {
			printf("----------   ----------   ----------   ----------   ----------   ----------   ----------   ----------   \n");
		}
		else if ((i + 4) % 6 == 0) {
			printf("    %s     |     %s     |     %s     |     %s     |     %s     |     %s     |     %s     |     %s     \n", "1a", "1a", "1a", "1a", "1a", "1a", "1a", "1a");
		}
		else {
			printf("           |            |            |            |            |            |            |            \n");
		}
	}
};

void Board::flip_board() {

};

void Board::draw_flip_board() {

};