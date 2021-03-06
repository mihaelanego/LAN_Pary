#include "queueGames.h"
#include "Game.h"
#include "Team.h"
#include <iostream>
using namespace std;

queueGame::queueGame(int capacity) {
	game = new	Game[capacity];
	this->capacity = capacity;
	front = 0;
	rear = -1;
	count = 0;
}

queueGame::~queueGame() {
	delete[] game;
}

Game queueGame::pop() {
	Game toBeDeleted = game[front];
	front = (front + 1) % capacity;
	count--;

	return toBeDeleted;
}

void queueGame::push(Game game) {
	rear = (rear + 1) % capacity;
	this->game[rear] = game;
	count++;
}

Game queueGame::peek() {
	return game[front];
}

int queueGame::getSize() {
	return count;
}


bool queueGame::isEmpty()
{
	return (getSize() == 0);
}

bool queueGame::isFull()
{
	return (getSize() == capacity);
}

ostream& operator << (ostream& stream, queueGame& games) {

	while (!games.isEmpty()) {
		Game gm = games.peek();

		stream << gm;
		games.pop();
	}

	return stream;
}

queueGame& queueGame::operator=(queueGame& qg) {
	this->game = qg.game;
	this->capacity = qg.capacity;
	this->front = qg.front;
	this->rear = qg.rear;
	this->count = qg.count;

	return*this;
}
