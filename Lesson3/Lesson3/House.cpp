#include "House.h"
House::House() {}
House::~House() {}
House::House(int _oid, string _name, float _posX, float _posY) {
	this->oid = _oid;
	this->name = _name;
	this->position[0] = _posX;
	this->position[1] = _posY;
}
int House::getId() {
	return this->oid;
}
string House::getName() {
	return this->name;
}
void House::move(float _x, float _y) {
	cout << getName() << " can't move.\n";
}
void House::printPosition() {
	cout << "Position of " << getName() << " is: (" << position[0] << ", " << position[1] << ").\n";
}