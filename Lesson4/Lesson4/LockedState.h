#pragma once
#include "State.h"
#include <iostream>
using namespace std;

class ClosedState;

class LockedState : public State
{
public:
	void printState(StateContext* sc);
};