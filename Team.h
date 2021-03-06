#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "listPlayers.h"
using namespace std;
class Team {
private:
	int playersNumber = 0;
	string teamName;
	listPlayers players;
public:
	void setTeamName(string teamName);
	void setPlayersNumber(int playersNumber);
	string getTeamName();
	friend istream& operator >> (istream&, Team&);
	float teamScore();

	listPlayers getPlayers() {
		return players;
	}
	void addPoint();

};

