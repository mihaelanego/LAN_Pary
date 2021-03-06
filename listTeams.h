#pragma once
#include "Team.h"
#include "Player.h"

struct teamNode {
	Team team;
	teamNode* next = NULL;
	teamNode* prev = NULL;
};

class listTeams {
public:
	teamNode* head = NULL;

	void add(Team);
	void deleteNode(int);
	friend ostream& operator << (ostream&, listTeams&);
};

