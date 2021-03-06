
#include "listPlayers.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void listPlayers::add(Player p){
	playerNode* newNode = new playerNode;

	newNode->player = p;
	newNode->next = NULL;
	if (head != NULL) {
		playerNode* currentNode = head;
		while (currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	else {
		head = newNode;
	}
}