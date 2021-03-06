#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;


void Player::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Player::setSecondName(string secondName) {
	this->secondName = secondName;
}

void Player::setPoints(int points) {
	this->points = points;
}

istream& operator >> (istream& in, Player& p) {
	in >> p.firstName;
	in >> p.secondName;
	in >> p.points;

	return in;
}

int Player::getPoints() {
	return points;
}