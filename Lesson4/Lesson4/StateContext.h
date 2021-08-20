#pragma once
#include "OpenState.h"
#include "LockedState.h"
#include "ClosedState.h"

class StateContext
{
private:
	State* s;
	int m_stateCount = 0;
public:
	StateContext() {
		s = new OpenState();
	}
	~StateContext() {};
	int getStateCount();
	void setState(State* newState);
	void printState();
};

