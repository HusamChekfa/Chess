#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <iostream>
#include <string>

// #include "Board.hpp"

using namespace std;

class Piece {
	public:
	  // Piece(); // pure virtual constructor ?
	  // ~Piece(); // pure virtual destructor ?
	  string getName() { return name; };
	  string getChName() { return chName; };
	  virtual void move() = 0;
	  bool getCanMove() { return canMove; };
	  void setCanMove(bool move) { canMove = move; };
	  bool getPinned() { return pinned; };
	  void setPinned(bool pin) { pinned = pin; };
	  bool getActive() { return active; };
	  void setActive(bool active_) { active = active_; };
	  unsigned int getRow() { return row; };
	  void setRow(unsigned int row_) { row = row_; };
	  char getColumn() { return column; };
	  void setColumn(char column_) { column = column_; };
	  //bool getChecked() { return checked; };
	  //void setChecked(bool checked_) { checked = checked_; };
	  bool getWhite() { return white; };
	  void setWhite(bool white_) { white = white_; };
	  char getAbbr() { return abbreviation; };
	  void setAbbr(char abbr_) { abbreviation = abbr_; };
	  // virtual vector<Square> getMoves() = 0;
	  string printPiece() {
		  string printPiece = "";
		  if (white) { printPiece += '1'; }
		  else { printPiece += '2'; }
		  printPiece += abbreviation;
		  return printPiece;
	  }
	  // vector<Square> getMoveTo() { return moveTo; };
	  bool getMoved() { return hasMoved; };
	  void setMoved(bool moved_) { hasMoved = moved_; };

	private:
	  string name;
	  string chName; // string instead of char* // 1 or 2 + first char of name
	  bool pinned = false; // piece cannot move if true - will help for stalemate check and legal moves
	  bool active = true; // all pieces start active - cannot move inactive pieces (gone from board)
	  bool canMove = false;
	  //bool checked = false;
	  bool white = false;
	  unsigned int row = 0;
	  char column = 'z';
	  char abbreviation = 'L';
	  // vector<Square> moveTo;
	  bool hasMoved = false;
};

class Pawn : public Piece {
	public:
		Pawn();
		~Pawn();
		virtual void move() {};
		// virtual vector<Square> getMoves() override;
	private:
		string name = "Pawn";
		char abbreviation = 'P';
};

class Knight : public Piece {
	public:
		Knight();
		~Knight();
		virtual void move() {};
		// virtual vector<Square> getMoves() override;
	private:
		string name = "Knight";
};

class Bishop : public Piece {
	public:
		Bishop();
		~Bishop();
		virtual void move() {};
		// virtual vector<Square> getMoves() override;
	private:
		string name = "Bishop";
		bool white = false; // set one to true
};

class Rook : public Piece {
	public:
		Rook();
		~Rook();
		virtual void move() {};
		// virtual vector<Square> getMoves() override;
	private:
		string name = "Rook";
};

class Queen : public Piece {
	public:
		Queen();
		~Queen();
		virtual void move() {};
		// virtual vector<Square> getMoves() override;
	private:
		string name = "Queen";
};

class King : public Piece {
	public:
		King();
		~King();
		virtual void move() {};
		// virtual vector<Square> getMoves() override;
		bool getChecked() { return checked; };
		void setChecked(bool checked_) { checked = checked_; };
	private:
		string name = "King";
		bool checked = false;
};

#endif