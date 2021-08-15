#pragma once
#include "DynamicObject.h"
class Car :
	public DynamicObject
{
public:
	Car();
	Car(int _oid, string _name, float _posX, float _posY);
	~Car();
	int getId();
	string getName();
	void move(float _x, float _y);
	void printPosition();
};