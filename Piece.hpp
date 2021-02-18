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
	  bool setCanMove(bool move) { canMove = move; };

	private:
	  string name;
	  string chName; // string instead of char* // 1 or 2 + first char of name
	  bool pinned = false; // piece cannot move if true - will help for stalemate check and legal moves
	  bool active = true; // all pieces start active - cannot move inactive pieces (gone from board)
	  bool canMove = false;
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
	private:
		string name = "King";
};

#endif