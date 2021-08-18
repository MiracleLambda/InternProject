#include "ClosedState.h"
#include "StateContext.h"
#include <iostream>

void ClosedState::printState(StateContext* sc) {
	cout << "Closed" << endl;
	if ((sc->getStateCount() / 2) % 2 == 1) {
		sc->setState(new OpenState);
	}
	else {
		sc->setState(new LockedState);
	}
}