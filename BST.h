#pragma once
#include <iostream>
#include <string>
#include "Team.h"
#include "Player.h"
#include "listTeams.h"
class BST {
public:
	Team data;
	BST* left;
	BST* right;

	BST();
	BST(Team);
	BST* insert_team(BST*, Team);
	void display_teams(ostream&, BST*);

};

