#pragma once
#include "BaseObject.h"
class StaticObject :
    public BaseObject
{
public:
	StaticObject();
	StaticObject(int _oid, string _name, float _posX, float _posY);
	virtual ~StaticObject() {};
	/*int getId();
	string getName();
	void move(float _x, float _y);
	void printPosition();*/
};

