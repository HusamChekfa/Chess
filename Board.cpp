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

string Board::helper_printSquare(unsigned int& val) {
	string squareName = "";
	//unsigned int temp = val;
	squareName += (val % 8 + 97); // add char
	squareName += (to_string((val / 8) + 1));

	if (val % 8 == 7) {
		if (val == 7) { val = 0; }
		else { val -= 15; }
	}
	else { ++val; }
	
	return squareName;
};
//aaa
/*
void Board::helper_draw_board() {

};
*/
void Board::draw_board() {

	// unsigned squareStr = 56;
	// helper_printSquare(squareStr).c_str()
	// theBoard.at(56).printSquareTwo().c_str()
	// theBoard.at(56).getPiece()->printPiece().c_str()
	//unsigned int pNum = 56;
	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
	printf("|::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |\n");
	printf("|:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|            |\n");
	printf("|:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |\n", 
		theBoard.at(56).printPiece().c_str(), theBoard.at(57).printPiece().c_str(), theBoard.at(58).printPiece().c_str(), theBoard.at(59).printPiece().c_str(),
		theBoard.at(60).printPiece().c_str(), theBoard.at(61).printPiece().c_str(), theBoard.at(62).printPiece().c_str(), theBoard.at(63).printPiece().c_str());
	printf("|:::         |            |:::         |            |:::         |            |:::         |            |\n");
	printf("|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|\n", "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8");

	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
	printf("|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|\n");
	printf("|            |:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|\n");
	printf("|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|\n", 
		theBoard.at(48).printPiece().c_str(), theBoard.at(49).printPiece().c_str(), theBoard.at(50).printPiece().c_str(), theBoard.at(51).printPiece().c_str(),
		theBoard.at(52).printPiece().c_str(), theBoard.at(53).printPiece().c_str(), theBoard.at(54).printPiece().c_str(), theBoard.at(55).printPiece().c_str());
	printf("|            |:::         |            |:::         |            |:::         |            |:::         |\n");
	printf("|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|\n", "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7");

	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
	printf("|::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |\n");
	printf("|:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|            |\n");
	printf("|:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |\n", 
		theBoard.at(40).printPiece().c_str(), theBoard.at(41).printPiece().c_str(), theBoard.at(42).printPiece().c_str(), theBoard.at(43).printPiece().c_str(),
		theBoard.at(44).printPiece().c_str(), theBoard.at(45).printPiece().c_str(), theBoard.at(46).printPiece().c_str(), theBoard.at(47).printPiece().c_str());
	printf("|:::         |            |:::         |            |:::         |            |:::         |            |\n");
	printf("|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|\n", "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6");

	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
	printf("|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|\n");
	printf("|            |:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|\n");
	printf("|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|\n", 
		theBoard.at(32).printPiece().c_str(), theBoard.at(33).printPiece().c_str(), theBoard.at(34).printPiece().c_str(), theBoard.at(35).printPiece().c_str(),
		theBoard.at(36).printPiece().c_str(), theBoard.at(37).printPiece().c_str(), theBoard.at(38).printPiece().c_str(), theBoard.at(39).printPiece().c_str());
	printf("|            |:::         |            |:::         |            |:::         |            |:::         |\n");
	printf("|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|\n", "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5");

	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
	printf("|::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |\n");
	printf("|:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|            |\n");
	printf("|:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |\n", 
		theBoard.at(24).printPiece().c_str(), theBoard.at(25).printPiece().c_str(), theBoard.at(26).printPiece().c_str(), theBoard.at(27).printPiece().c_str(),
		theBoard.at(28).printPiece().c_str(), theBoard.at(29).printPiece().c_str(), theBoard.at(30).printPiece().c_str(), theBoard.at(31).printPiece().c_str());
	printf("|:::         |            |:::         |            |:::         |            |:::         |            |\n");
	printf("|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|\n", "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4");

	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
	printf("|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|\n");
	printf("|            |:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|\n");
	printf("|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|\n", 
		theBoard.at(16).printPiece().c_str(), theBoard.at(17).printPiece().c_str(), theBoard.at(18).printPiece().c_str(), theBoard.at(19).printPiece().c_str(),
		theBoard.at(20).printPiece().c_str(), theBoard.at(21).printPiece().c_str(), theBoard.at(22).printPiece().c_str(), theBoard.at(23).printPiece().c_str());
	printf("|            |:::         |            |:::         |            |:::         |            |:::         |\n");
	printf("|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|\n", "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3");

	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
	printf("|::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |\n");
	printf("|:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|            |\n");
	printf("|:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |\n", 
		theBoard.at(8).printPiece().c_str(), theBoard.at(9).printPiece().c_str(), theBoard.at(10).printPiece().c_str(), theBoard.at(11).printPiece().c_str(),
		theBoard.at(12).printPiece().c_str(), theBoard.at(13).printPiece().c_str(), theBoard.at(14).printPiece().c_str(), theBoard.at(15).printPiece().c_str());
	printf("|:::         |            |:::         |            |:::         |            |:::         |            |\n");
	printf("|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|\n", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2");

	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");
	printf("|            |::::::::::::|            |::::::::::::|            |::::::::::::|            |::::::::::::|\n");
	printf("|            |:::      :::|            |:::      :::|            |:::      :::|            |:::      :::|\n");
	printf("|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|     %s     |:::  %s  :::|\n", 
		theBoard.at(0).printPiece().c_str(), theBoard.at(1).printPiece().c_str(), theBoard.at(2).printPiece().c_str(), theBoard.at(3).printPiece().c_str(),
		theBoard.at(4).printPiece().c_str(), theBoard.at(5).printPiece().c_str(), theBoard.at(6).printPiece().c_str(), theBoard.at(7).printPiece().c_str());
	printf("|            |:::         |            |:::         |            |:::         |            |:::         |\n");
	printf("|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|          %s|::::::::  %s|\n", "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1");

	printf(" ----------- + ---------- + ---------- + ---------- + ---------- + ---------- + ---------- + -----------\n");

	
};

void Board::flip_board() {

};

void Board::draw_flip_board() {
	// same as draw_board()
	// only change is reverse print of theBoard
	// squares printed same
};