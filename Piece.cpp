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

Knight::Knight() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('N');
};

Knight::~Knight() {

};

Bishop::Bishop() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('B');
};

Bishop::~Bishop() {

};

Rook::Rook() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('R');
};

Rook::~Rook() {

};

Queen::Queen() {
	setPinned(false);
	setCanMove(false);
	setActive(true);
	setWhite(false);
	setAbbr('Q');
};

Queen::~Queen() {

};

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