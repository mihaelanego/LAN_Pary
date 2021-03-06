#include "teamStack.h"
#include "Team.h"
#include <iostream>
#include <string>
using namespace std;
teamStack::teamStack(int capacity) {
	this->capacity = capacity;
	team = new Team[capacity];
	top = -1;
	count = 0;
}

teamStack::~teamStack() {
	delete[] team;
}

Team teamStack::pop() {
	count--;
    return team[top--];
}

void teamStack::push(Team& team) {
    this->team[++top] = team;
	count++;
}

Team teamStack::peek() {
	return team[top];
}

int teamStack::getSize() {
	return count;
}

ostream& operator << (ostream& stream, teamStack& stack) {
	while (!stack.isEmpty()) {  
		Team tm = stack.pop();
		stream << tm.getTeamName();

		int size1 = tm.getTeamName().size();
		size1 = 33 - size1;
		stream.width(size1);

		stream << "-  ";
		stream << to_string(tm.teamScore()).substr(0, to_string(tm.teamScore()).find(".") + 3) << endl;
		
	}
	return stream;
}

teamStack& teamStack:: operator=(teamStack& tStack) {
	this->team = tStack.team;
	this->top = tStack.top;
	this->capacity = tStack.capacity;
	this->count = tStack.count;

	return*this;
}


bool teamStack::isEmpty() {  
	return (top == -1);
}

bool teamStack::isFull() {
	return (top == capacity - 1);
}