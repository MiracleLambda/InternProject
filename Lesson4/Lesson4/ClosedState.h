#pragma once
#include "State.h"
using namespace std;

class OpenState;
class LockedState;

class ClosedState : public State
{
public:
	void printState(StateContext* sc);
};