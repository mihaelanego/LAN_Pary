#pragma once
#include "Team.h"
#include <iostream>
using namespace std;
class teamStack
{
    Team* team;
    int top;
    int capacity;
    int count;

public:
    teamStack(int);     
    ~teamStack();                   
    void push(Team&);
    Team pop();
    Team peek();
    int getSize();
    bool isEmpty();
    bool isFull();
    friend ostream& operator << (ostream&, teamStack&);
    teamStack& operator=(teamStack&);
};

