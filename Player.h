#pragma once
#include <iostream>
using namespace std;
class Player {
private:
	string firstName;
	string secondName;
	int points = 0;
public:

	void setFirstName(string firstName);
	void setSecondName(string secondName);
	void setPoints(int points);
	int getPoints();
	friend istream& operator >> (istream&, Player&);

};

