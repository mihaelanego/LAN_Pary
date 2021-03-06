#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Team.h"
#include "Player.h"
#include "listTeams.h"
#include "BST.h"

BST::BST() {
	
	left = NULL;
	right = NULL;
}

BST::BST(Team data) {
	this->data = data;
	left = right = NULL;
}

BST* BST::insert_team(BST* root, Team t) {
	if (!root) {
		return new BST(t);
	}

	if (t.teamScore() > root->data.teamScore()) {
		root->right = insert_team(root->right, t);
	}
	else {
		if (t.teamScore() == root->data.teamScore()) {
			if (t.getTeamName() > root->data.getTeamName()) {
				root->right = insert_team(root->right, t);
			}
			else {
				root->left = insert_team(root->left, t);
			}
		}
		else {
			root->left = insert_team(root->left, t);
		}
	}

	return root;
}

void BST::display_teams(ostream& out, BST* root) {
	if (!root) {
		return;
	}

	display_teams(out, root->right);

	out << root->data.getTeamName(); 

	int size1 = root->data.getTeamName().size();
	size1 = 37 - size1;

	out.width(size1);
	out << "-  ";

	float value = (int)(root->data.teamScore() * 100 + .5);
	value =  (float)value / 100;

	out<< to_string(value).substr(0, to_string(value).find(".") + 3) << endl;

	display_teams(out, root->left);

}
