#pragma once
#include "State.h"
#include <iostream>
using namespace std;

class ClosedState;

class OpenState : public State
{
public:
	void printState(StateContext* sc);
};

