#include "OpenState.h"
#include "StateContext.h"
#include <iostream>

void OpenState::printState(StateContext* sc) {
	cout <<	"Open" << endl;
	sc->setState(new ClosedState);
}
