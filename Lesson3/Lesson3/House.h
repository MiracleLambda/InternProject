#pragma once
#include "StaticObject.h"
class House :
	public StaticObject
{
public:
	House();
	House(int _oid, string _name, float _posX, float _posY);
	~House();
	int getId();
	string getName();
	void move(float _x, float _y);
	void printPosition();
};