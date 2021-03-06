#pragma once
#include <iostream>
#include <string>
#include "Team.h"
#include "BST.h"

struct AVL {
	Team data;
	struct AVL* left = NULL;
	struct AVL* right = NULL;
};

class AVL_tree {
public:
	int getHeight(AVL*);
	int diff(AVL*);
	AVL* RR_rotate(AVL*);
	AVL* LL_rotate(AVL*);
	AVL* RL_rotate(AVL*);
	AVL* LR_rotate(AVL*);
	AVL* balance(AVL*);
	AVL* insert(AVL*, Team);
	void printLevel(ostream& out, AVL* t, int root_height = 0);
	void readBST(BST*, AVL*&);

};

