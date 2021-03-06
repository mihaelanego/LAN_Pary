#pragma once
#include"Player.h"

struct playerNode {
	Player player;
	playerNode* next = NULL;
};

class listPlayers{
public:
	playerNode* head = NULL;
	void add(Player);

};

