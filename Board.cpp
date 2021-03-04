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
	theBoard.resize(64); // board = 64 squares
	player1.resize(16); // player 1 = 16 pieces
	player2.resize(16); // player 2 = 16 pieces
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

	for (unsigned int i = 0; i < 10; ++i) { // pawns and knights can move at beginning // pawns = 0 -> 7 ; knights 8 -> 9
		player1.at(i)->setCanMove(true);
		player2.at(i)->setCanMove(true);
	}

	for (unsigned int i = 0; i < 16; ++i) {
		//player2.at(i)->setWhite(false);
		player1.at(i)->setWhite(true);
	}

	// innit board squares
	// theBoard = { Square("a1") };

	for (unsigned int i = 0; i < 64; ++i) {
		theBoard.at(i).setColumn((i % 8) + 97); // a = 97 ascii
		theBoard.at(i).setRow((i / 8) + 1);
	}

	// set piece pointers of sqaures
	// player1
	theBoard.at(0).piece = player1.at(12);
	theBoard.at(7).piece = player1.at(13);
	theBoard.at(1).piece = player1.at(8);
	theBoard.at(6).piece = player1.at(9);
	theBoard.at(2).piece = player1.at(10);
	theBoard.at(5).piece = player1.at(11);
	theBoard.at(3).piece = player1.at(14);
	theBoard.at(4).piece = player1.at(15);
	for (unsigned int i = 0; i < 8; ++i) {
		theBoard.at(i + 8).piece = player1.at(i);
	}
	// player2
	theBoard.at(56).piece = player2.at(12);
	theBoard.at(63).piece = player2.at(13);
	theBoard.at(57).piece = player2.at(8);
	theBoard.at(62).piece = player2.at(9);
	theBoard.at(58).piece = player2.at(10);
	theBoard.at(61).piece = player2.at(11);
	theBoard.at(59).piece = player2.at(14);
	theBoard.at(60).piece = player2.at(15);
	for (unsigned int i = 0; i < 8; ++i) {
		theBoard.at(i + 48).piece = player2.at(i);
	}
	
	/*
	for (unsigned int i = 0; i < 16; ++i) { theBoard.at(i).piece = player1.at(i); }
	for (unsigned int i = 48; i < 64; ++i) { theBoard.at(i).piece = player2.at(i - 48); }
	*/

	// set square colours
	for (unsigned int i = 0; i < 64; ++i) {
		if (i % 2 == 0) { theBoard.at(i).setWhiteSquare(false); }
		else { theBoard.at(i).setWhiteSquare(true); }
	}
};

Board::~Board() {

};
//aaa
/*
void Board::helper_draw_board() {

};
*/
void Board::draw_board() {
	unsigned int squareNum = 63;
	unsigned int pieceNum = 63;
	for (unsigned int i = 0; i < 49; ++i) {
		if (i % 6 == 0) {
			printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
		}
		/*else if ((i + 3) % 6 == 0) {
			printf("|     %s     |     %s     |     %s     |     %s     |     %s     |     %s     |     %s     |     %s     |\n", "1a", "1a", "1a", "1a", "1a", "1a", "1a", "1a");
		}*/
		else if ((i % 12) == 3) {
			printf("|:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |\n", theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str());
		}
		else if ((i % 12) == 9) {
			printf("|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|\n", theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str(), theBoard.at(pieceNum).printPiece(pieceNum).c_str());
		}
		else if (i % 12 == 4) {
			printf("|:::         |            |:::         |            |:::         |            |:::         |            |\n");
		}
		else if (i % 12 == 10) {
			printf("|            |:::         |            |:::         |            |:::         |            |:::         |\n");
		}
		else if ((i % 12) < 6) {
			if ((i % 12) == 2 || (i % 12) == 4) {
				printf("|:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|            |\n");
			}
			else if (i % 12 == 5) {
				printf("|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|\n", theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str());
			}
			else {
				printf("|::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |\n");
			}
		}
		/*else if ((i % 12) < 6) {
			printf("|------------|            |------------|            |------------|            |------------|            |\n");
		}*/
		else {
			if ((i % 12) == 8 || (i % 12) == 10) {
				printf("|            |:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|\n");
			}
			else if (i % 12 == 11) {
				printf("|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|\n", theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str(), theBoard.at(squareNum).printSquare(squareNum).c_str());
			}
			else {
				printf("|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|\n");
			}
		}
		/*else {
			printf("|            |------------|            |------------|            |------------|            |------------|\n");
		}*/
		/*else {
			printf("|            |            |            |            |            |            |            |            |\n");
		}*/
	}
};

void Board::flip_board() {

};

void Board::draw_flip_board() {
	// same as draw_board()
	// only change is reverse print of theBoard
	// squares printed same
};