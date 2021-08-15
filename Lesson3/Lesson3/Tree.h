#pragma once
#include "StaticObject.h"
class Tree :
    public StaticObject
{
public:
	Tree();
	Tree(int _oid, string _name, float _posX, float _posY);
	~Tree();
	int getId();
	string getName();
	void move(float _x, float _y);
	void printPosition();
};

