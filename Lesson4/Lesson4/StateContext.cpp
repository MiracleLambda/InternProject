#include "StateContext.h"

int StateContext::getStateCount() {
	return m_stateCount;
}

void StateContext::setState(State* newState) {
	State* toDel = s;
	s = newState;
	delete toDel;
	m_stateCount++;
}

void StateContext::printState() {
	s->printState(this);
}