#include "Car.h"
Car::Car() {}
Car::~Car() {}
Car::Car(int _oid, string _name, float _posX, float _posY) {
	this->oid = _oid;
	this->name = _name;
	this->position[0] = _posX;
	this->position[1] = _posY;
}
int Car::getId() {
	return this->oid;
}
string Car::getName() {
	return this->name;
}
void Car::move(float _x, float _y) {
	position[0] = _x;
	position[1] = _y;
}
void Car::printPosition() {
	cout << "Position of " << getName() << " is: (" << position[0] << ", " << position[1] << ").\n";
}