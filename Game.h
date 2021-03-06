#pragma once
#include <iostream>
#include "Team.h"
#include "listTeams.h"
using namespace std;
class Game {
private:
	Team t1;
	Team t2;
public:
	void set_t1(Team);
	void set_t2(Team);
	Team get_t1();
	Team get_t2();
	friend ostream& operator << (ostream&, Game&);
	Game& operator=(Game&);


};

