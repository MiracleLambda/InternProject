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
	int getStateCount() {
		return m_stateCount;
	}

	void setState(State* newState) {
		State* toDel = s;
		s = newState;
		delete toDel;
		m_stateCount++;
	}

	void printState() {
		s->printState(this);
	}
};

