#include "LockedState.h"
#include "StateContext.h"
#include <iostream>

void LockedState::printState(StateContext* sc) {
	cout << "Locked" << endl;
	sc->setState(new ClosedState);
}