#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <iostream>
#include <string>

#include "Board.hpp"

using namespace std;

class Piece {
	public:
	  Piece();
	  ~Piece();
	  string getName();
	  char* getChName();
	  virtual void move() = 0;
	private:
	  string name;
	  char* chName;
};

class Pawn : public Piece {
	public:
	private:
};

class Knight : public Piece {
	public:
	private:
};

class Bishop : public Piece {
	public:
	private:
};

class Rook : public Piece {
	public:
	private:
};

class Queen : public Piece {
	public:
	private:
};

class King : public Piece {
	public:
	private:
};

#endif