#include "Motorbike.h"
Motorbike::Motorbike() {}
Motorbike::~Motorbike() {}
Motorbike::Motorbike(int _oid, string _name, float _posX, float _posY) : DynamicObject(_oid, _name, _posX, _posY) {
}
int Motorbike::getId() {
	return this->oid;
}
string Motorbike::getName() {
	return this->name;
}
void Motorbike::move(float _x, float _y) {
	posX = _x;
	posY = _y;
}
void Motorbike::printPosition() {
	cout << "\tPosition of " << getName() << " is: (" << posX << ", " << posY << ").\n";
}