#include "listTeams.h"
#include "Player.h"
#include <iostream>
using namespace std;

void listTeams::add(Team t) {
	teamNode* newNode = new teamNode;

	newNode->team = t;
	newNode->next = head;
	if (head != NULL) {
		head->prev = newNode;
	}

	head = newNode;
}

ostream& operator << (ostream& stream, listTeams& list) {
	teamNode* current = list.head;
	while (current != NULL) {
		stream << current->team.getTeamName() << endl;
		current = current->next;
	};

	return stream;
}

void listTeams::deleteNode(int index) {
	teamNode** headRef = &head;
	teamNode* current = head;

	for (int i = 0; i < index; i++) {
		if (current == NULL) {
			break;
		}
		current = current->next;
	}

	if (*headRef == NULL || current == NULL)
		return;

	if (current == *headRef)
		*headRef = current->next;

	if (current->next != NULL)
		current->next->prev = current->prev;

	if (current->prev != NULL)
		current->prev->next = current->next;
}
