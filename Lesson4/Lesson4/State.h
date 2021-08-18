#pragma once
class StateContext;

class State
{
public:
	virtual ~State() {};
	virtual void printState(StateContext* sc) = 0;
};

