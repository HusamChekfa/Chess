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

	for (unsigned int i = 0; i < 15; ++i) {
		player1.at(i)->setPinned(false);
		player2.at(i)->setPinned(false);
		player1.at(i)->setCanMove(false);
		player1.at(i)->setCanMove(false);
		player1.at(i)->setActive(true);
		player2.at(i)->setActive(true);
		player1.at(i)->setChecked(false);
		player2.at(i)->setChecked(false);
	}
	for (unsigned int i = 0; i < 10; ++i) { // pawns and knights can move at beginning // pawns = 0 -> 7 ; knights 8 -> 9
		player1.at(i)->setCanMove(true);
		player2.at(i)->setCanMove(true);
	}

	for (unsigned int i = 0; i < 16; ++i) { theBoard.at(i).piece = player1.at(i); }
	for (unsigned int i = 48; i < 64; ++i) { theBoard.at(i).piece = player2.at(i - 48); }
};

Board::~Board() {

};
//aaa
void Board::draw_board() {
	for (unsigned int i = 0; i < 49; ++i) {
		if (i % 6 == 0) {
			printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
		}
		/*else if ((i + 3) % 6 == 0) {
			printf("|     %s     |     %s     |     %s     |     %s     |     %s     |     %s     |     %s     |     %s     |\n", "1a", "1a", "1a", "1a", "1a", "1a", "1a", "1a");
		}*/
		else if ((i % 12) == 3) {
			printf("|:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |\n", "1a", "1a", "1a", "1a", "1a", "1a", "1a", "1a");
		}
		else if ((i % 12) == 9) {
			printf("|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|\n", "1a", "1a", "1a", "1a", "1a", "1a", "1a", "1a");
		}
		else if ((i % 12) < 6) {
			if ((i % 12) == 2 || (i % 12) == 4) {
				printf("|:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|            |\n");
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