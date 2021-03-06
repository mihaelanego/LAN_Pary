#include "AVL.h"
#include "Team.h"
#include "BST.h"
#include <iostream>
#include <string>

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int AVL_tree::getHeight(AVL* a) {
	int height = 0;

	if (a != NULL) {
		int l_height = getHeight(a->left);
		int r_height = getHeight(a->right);
		int max_height = max(l_height, r_height);
		height = max_height + 1;
	}

	return height;
}

int AVL_tree::diff(AVL* a) {
	int l_height = getHeight(a->left);
	int r_height = getHeight(a->right);

	int diff = l_height - r_height;
	return diff;
}

AVL* AVL_tree::RR_rotate(AVL* parent) {
	AVL* a;

	a = parent->right;
	parent->right = a->left;
	a->left = parent;

	return a;
}

AVL* AVL_tree::LL_rotate(AVL* parent) {
	AVL* a;

	a = parent->left;
	parent->left = a->right;
	a->right = parent;
	
	return a;
}

AVL* AVL_tree::LR_rotate(AVL* parent) {
	AVL* a;
	a = parent->left;
	parent->left = RR_rotate(a);

	return LL_rotate(parent);
}

AVL* AVL_tree::RL_rotate(AVL* parent) {
	AVL* a;
	a = parent->right;
	parent->right = LL_rotate(a);
	
	return RR_rotate(parent);
}

AVL* AVL_tree::balance(AVL* a) {
	int balance = diff(a);
	if (balance > 1) {
		if (diff(a->left) > 0)
			a = LL_rotate(a);
		else
			a = LR_rotate(a);
	}
	else if (balance < -1) {
		if (diff(a->right) > 0)
			a = RL_rotate(a);
		else
			a = RR_rotate(a);
	}
	return a;
}

AVL* AVL_tree::insert(AVL* r, Team t) {
	//cout << "Insereaza 1\n";
	if (r == NULL) {
		r = new AVL;
		r->data = t;
		r->left = NULL;
		r->right = NULL;
		return r;
	}
	else {
		if (t.teamScore() <= r->data.teamScore()) {
			r->left = insert(r->left, t);
			r = balance(r);
		}
		else {
			if (t.teamScore() > r->data.teamScore()) {
				r->right = insert(r->right, t);
				r = balance(r);
			}
		}
	}
	return r;
}

void AVL_tree::printLevel(ostream& out, AVL* t, int root_height) {
	if (t == NULL)
		return;
	if (root_height == 2) {
		out << t->data.getTeamName() << endl;
	}
	else {
		printLevel(out, t->right, root_height + 1);
		printLevel(out, t->left, root_height + 1);
	}
}

void AVL_tree::readBST(BST* root, AVL* &node) {
	if (!root) {
		return;
	}
	readBST(root->right, node);

	node = insert(node, root->data);

	readBST(root->left, node);
}


 




