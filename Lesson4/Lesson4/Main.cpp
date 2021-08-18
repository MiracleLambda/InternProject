#include <crtdbg.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <memory>
#include "StateContext.h"
#include "OpenState.h"
#include "LockedState.h"
#include "ClosedState.h"
using namespace std;

int main() {
	{
		cout << "START THE DOOR'S STATES PROGRAM!\n";
		StateContext* stateContext = new StateContext();
		for (int i = 0; i < 10; ++i)
		{
			stateContext->printState();
		}
		delete stateContext;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}