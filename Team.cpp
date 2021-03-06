#include "Team.h"
#include <iostream>
#include <fstream>
#include <string>
#include "listTeams.h"
#include "listPlayers.h"

using namespace std;

void Team::setTeamName(string teamName) {
	this->teamName = teamName;
}

void Team::setPlayersNumber(int playersNumber) {
	this->playersNumber = playersNumber;
}

string Team::getTeamName() {
	return this->teamName;
}

istream& operator >> (istream& in, Team& t) {
	in >> t.playersNumber;

	in.ignore();
	
	string teamName;
	getline(in, teamName);

	teamName.erase(teamName.find_last_not_of(" \n\r\t") + 1); //clean-up team name
	t.teamName = teamName;

	for (int i = 0; i < t.playersNumber; i++) {
		Player p;
		in >> p;
		t.players.add(p);
	}

	return in;
}

float Team::teamScore() {
	float score = 0.0;

	playerNode* current = players.head;
	while (current != NULL) {
		score += current->player.getPoints();
		current = current->next;
	}

	score = score / playersNumber;

	return score;
}

void Team::addPoint() {
	playerNode* current = players.head;

	while (current != NULL) {
		current->player.setPoints(current->player.getPoints() + 1);
		current = current->next;
	}
}

