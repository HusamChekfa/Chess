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
	Square(string tile) {
		column = tile.at(0);
		row = tile.at(1);
		piece = nullptr;
		whiteSquare = false;
	}
	*/
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
	void setPiece(Piece* piece1) { piece = piece1; piece->setColumn(column); piece->setRow(row); };
	bool getWhiteSquare() { return whiteSquare; };
	void setWhiteSquare(bool whiteSquare1) { whiteSquare = whiteSquare1; };

	string printSquareTwo() {
		string ret = "";
		ret += column;
		ret += to_string(row);
		return ret;
	}

	string printSquare(unsigned int& squareNum) {
		/*
		if (squareNum % 8 == 7) {
			if (squareNum == 7) { squareNum = 0; }
			else { squareNum -= 15; }
		}
		else { ++squareNum; }
		*/
		//char a = squareNum % 8 + 97;
		//unsigned int b = squareNum / 8 + 1;
		//--squareNum;
		//return a + to_string(b);
		--squareNum;
		return column + to_string(row);
		/*
		string print = "";
		if (column != 'i') { print += column; }
		else { print += ' '; }
		if (row != 9) { print += to_string(row); }
		else { print += ' '; }
		return print;
		*/
	}

	string printPiece(/*unsigned int& pieceNum*/) {
		/*
		if (pieceNum % 8 == 7) {
			if (pieceNum == 7) { pieceNum = 0; }
			else { pieceNum -= 15; }
		}
		else { ++pieceNum; }
		*/
		if (piece == nullptr) { return "  "; };
		return piece->printPiece();
	}

	Piece* piece = nullptr;
	unsigned int row = 9; // 1 - 8 .. rank
	char column = 'i'; // a - h .. file
	bool whiteSquare = false;
	// instead of holdColour 0-2, nullptr means nothing there, else check colour of piece

};

struct Move {
	Move() {}
	~Move() {}

	// Square squareMove;
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
	  vector<vector<Square>> getMoves1() { return moves1; };
	  vector<vector<Square>> getMoves2() { return moves2; };
	  void setMoves();

  private:
	  // create board of 64 squares
	  vector<Square> theBoard;
	  string helper_printSquare(unsigned int&);
	  // void helper_draw_board();

	  // player sizes can stay 16. if pawn promotes -> delete pawn + new queen same vector index
	  vector<Piece*> player1;
	  vector<Piece*> player2;
	  vector<vector<Square>> moves1;
	  vector<vector<Square>> moves2;
	  
};

#endif