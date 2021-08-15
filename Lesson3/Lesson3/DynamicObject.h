#pragma once
#include "BaseObject.h"
class DynamicObject :
	public BaseObject
{
public:
	DynamicObject();
	DynamicObject(int _oid, string _name, float _posX, float _posY);
	virtual ~DynamicObject() {};
	/*int getId();
	string getName();
	void move(float _x, float _y);
	void printPosition();*/
};

