#include "House.h"
House::House() {}
House::~House() {}
House::House(int _oid, string _name, float _posX, float _posY) : StaticObject(_oid, _name, _posX, _posY) {
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
	cout << "\tPosition of " << getName() << " is: (" << posX << ", " << posY << ").\n";
}