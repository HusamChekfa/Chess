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
	  bool getChecked() { return checked; };
	  void setChecked(bool checked_) { checked = checked_; };

	private:
	  string name;
	  string chName; // string instead of char* // 1 or 2 + first char of name
	  bool pinned = false; // piece cannot move if true - will help for stalemate check and legal moves
	  bool active = true; // all pieces start active - cannot move inactive pieces (gone from board)
	  bool canMove = false;
	  bool checked = false;
	  unsigned int row;
	  char column;
};

class Pawn : public Piece {
	public:
		Pawn();
		~Pawn();
		virtual void move() {};
	private:
		string name = "Pawn";
};

class Knight : public Piece {
	public:
		Knight();
		~Knight();
		virtual void move() {};
	private:
		string name = "Knight";
};

class Bishop : public Piece {
	public:
		Bishop();
		~Bishop();
		virtual void move() {};
	private:
		string name = "Bishop";
		bool white = false; // set one to true
};

class Rook : public Piece {
	public:
		Rook();
		~Rook();
		virtual void move() {};
	private:
		string name = "Rook";
};

class Queen : public Piece {
	public:
		Queen();
		~Queen();
		virtual void move() {};
	private:
		string name = "Queen";
};

class King : public Piece {
	public:
		King();
		~King();
		virtual void move() {};
		// bool getChecked() { return checked; };
		// void setChecked(bool checked_) { checked = checked_; };
	private:
		string name = "King";
		// bool checked = false;
};

#endif