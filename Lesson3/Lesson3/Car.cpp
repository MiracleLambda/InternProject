#include "Car.h"
Car::Car() {}
Car::~Car() {}
Car::Car(int _oid, string _name, float _posX, float _posY) : DynamicObject(_oid, _name, _posX, _posY) {
}
int Car::getId() {
	return this->oid;
}
string Car::getName() {
	return this->name;
}
void Car::move(float _x, float _y) {
	posX = _x;
	posY = _y;
}
void Car::printPosition() {
	cout << "\tPosition of " << getName() << " is: (" << posX << ", " << posY << ").\n";
}