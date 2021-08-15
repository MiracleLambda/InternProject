#include "Motorbike.h"
Motorbike::Motorbike() {}
Motorbike::~Motorbike() {}
Motorbike::Motorbike(int _oid, string _name, float _posX, float _posY) {
	this->oid = _oid;
	this->name = _name;
	this->position[0] = _posX;
	this->position[1] = _posY;
}
int Motorbike::getId() {
	return this->oid;
}
string Motorbike::getName() {
	return this->name;
}
void Motorbike::move(float _x, float _y) {
	position[0] = _x;
	position[1] = _y;
}
void Motorbike::printPosition() {
	cout << "Position of " << getName() << " is: (" << position[0] << ", " << position[1] << ").\n";
}