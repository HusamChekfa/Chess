#include <iostream>
#include <string>

#include "Piece.hpp"
#include "Board.hpp"

using namespace std;

Pawn::Pawn() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('P');
};

Pawn::~Pawn() {

};

/*
vector<Square> Pawn::getMoves() {
	vector<Square> v;
	string pSquare = printPiece();
	char cSquare = getColumn();
	unsigned int rSquare = getRow();
	
	// max 4 moves if !hasMoved
	// max 3 moves if hasMoved
	
	
	if !active
		return v
	if pinned
		return v

	if white {
		if square + 1 row . piece != nullptr
			++ vector
			if !hasMoved
				if square + 2 row . piece != nullptr
					++ vector
		if square + 1 row + 1 column exists && held by !white
			++ vector (TAKE) // string has TAKE
		if square + 1 row - 1 column exists && held by !white
			++ vector (TAKE) // string has TAKE w Piece name

		
		if moves leads to row 8, return (PROMOTION) // take + promotion take if applicable
	}
	else {
		if square - 1 row . piece != nullptr
			++ vector
			if !hasMoved
				if square - 2 row . piece != nullptr
					++ vector
		if square - 1 row + 1 column exists && held by white
			++ vector (TAKE) // string has TAKE
		if square - 1 row - 1 column exists && held by white
			++ vector (TAKE) // string has TAKE w Piece name


		if moves leads to row 1, return (PROMOTION)
	}

	return v;
};
*/

// move () if --> 8 call promotion , delete, new (should type promotion !)

Knight::Knight() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('N');
};

Knight::~Knight() {

};

/*
vector<Square> Knight::getMoves() {
	vector<Square> v;
	string pSquare = printPiece();
	char cSquare = getColumn();
	unsigned int rSquare = getRow();

	// if !active
		// return v
	// if pinned
		// return v

	// 8 max moves
	
	check if each square exists ofc
	1 <= row <= 8
	a <= column <= h

	check if square holds enemy piece
	if square.piece.getWhite != getwhite
		++ vector

	

	curr square:
	+ 1 column + 2 row
	+ 2 column + 1 row
	+ 1 column - 2 row
	+ 2 column - 1 row
	- 1 column - 2 row
	- 2 column - 1 row
	- 1 column + 2 row
	- 2 column + 1 row

	return v;
};
*/

Bishop::Bishop() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('B');
};

Bishop::~Bishop() {

};

/*
vector<Square> Bishop::getMoves() {
	vector<Square> v;
	string pSquare = printPiece();
	char cSquare = getColumn();
	unsigned int rSquare = getRow();

	// if !active
		// return v
	// if pinned
		// return v

	// check 4 directions
	// upon reaching a square which holds ally do not include then stop // continue //, holds enemy include then stop // continue // , end of board include then stop // continue //

	return v;
};
*/

Rook::Rook() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('R');
};

Rook::~Rook() {

};

/*
vector<Square> Rook::getMoves() {
	vector<Square> v;
	string pSquare = printPiece();
	char cSquare = getColumn();
	unsigned int rSquare = getRow();

	// if !active
		// return v
	// if pinned
		// return v

	// check 4 directions
	// upon reaching a square which holds ally do not include then stop // continue //, holds enemy include then stop // continue // , end of board include then stop // continue //

	return v;
};
*/

Queen::Queen() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('Q');
};

Queen::~Queen() {

};

/*
vector<Square> Queen::getMoves() {
	vector<Square> v;
	string pSquare = printPiece();
	char cSquare = getColumn();
	unsigned int rSquare = getRow();

	// if !active
		// return v
	// if pinned
		// return v

	// combine bishop + rook

	return v;
};
*/

King::King() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('K');
	setChecked(false);
};

King::~King() {

};

/*
vector<Square> King::getMoves() {
	// vector<Square> v = getMoveTo();

	vector<Square> v;
	string pSquare = printPiece();
	char cSquare = getColumn();
	unsigned int rSquare = getRow();

	// if !active
		// return v
	// if pinned
		// return v

	// max 4 squares - forget about castle for now

	
	get square

	// do not check if active / pinned

	check if square exists
	check if square holds ally piece

	check :
	+ 1 row
	+ 1 column + 1 row
	+ 1 column
	+ 1 column - 1 row
	- 1 row
	- 1 column - 1 row
	- 1 column
	- 1 column + 1 row
	
	return v;
};
*/