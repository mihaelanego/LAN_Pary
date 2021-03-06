#include "Game.h"
#include "listPlayers.h"
#include "Team.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void Game::set_t1(Team t1) {
	this->t1 = t1;
}

void Game::set_t2(Team t2) {
	this->t2 = t2;
}

Team Game::get_t1() {
	return t1;
}

Team Game::get_t2() {
	return t2;
}

ostream& operator << (ostream& out, Game& game) {
	out << game.t1.getTeamName();

	int size1 = game.t1.getTeamName().size();
	size1 = 34 - size1;
	out.width(size1);

	out << "-";
	out.width(33);

	out << game.t2.getTeamName();
	out << endl;
	 
	return out;
}

Game&Game:: operator=(Game& g) {
	this->t1 = g.t1;
	this->t2 = g.t2;

	return*this;
}