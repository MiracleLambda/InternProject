#pragma once
#include "DynamicObject.h"
class Motorbike :
	public DynamicObject
{
public:
	Motorbike();
	Motorbike(int _oid, string _name, float _posX, float _posY);
	~Motorbike();
	int getId();
	string getName();
	void move(float _x, float _y);
	void printPosition();
};