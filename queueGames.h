#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "Team.h"
using namespace std;
class queueGame
{
	Game* game;   	
	int capacity;   
	int front;  	
	int rear;   	
	int count;  	

public:
	queueGame(int);	 
	~queueGame();		
	Game pop();		
	void push(Game);	
	Game peek();		
	int getSize();	
	bool isEmpty();
	bool isFull();
	friend ostream& operator << (ostream&, queueGame&);
	queueGame& operator=(queueGame&);

};

