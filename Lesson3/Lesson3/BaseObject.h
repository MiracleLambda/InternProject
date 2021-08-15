#pragma once
#include <string>
#include <iostream>
using namespace std;

class BaseObject {
protected:
	int oid;
	string name;
	float position[2];
public:
	BaseObject();
	BaseObject(int _oid, string _name, float _posX, float _posY);
	virtual ~BaseObject() {};
	virtual string getName() { return this->name; };
	virtual int getId() { return this->oid; };
	virtual void move(float addX, float addY) {};
	virtual void printPosition() {};
};

