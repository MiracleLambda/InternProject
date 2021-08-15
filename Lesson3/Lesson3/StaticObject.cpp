#include "StaticObject.h"
StaticObject::StaticObject() {}
StaticObject::StaticObject(int _oid, string _name, float _posX, float _posY) {
	this->oid = _oid;
	this->name = _name;
	this->position[0] = _posX;
	this->position[1] = _posY;
}
//int staticobject::getId() {
//	return this->oid;
//}
//string staticobject::getName() {
//	return this->name;
//}
//void staticobject::move(float _x, float _y) {
//	cout << "this object can't move.\n";
//}
//void staticobject::printPosition() {
//	cout << "position of " << getname() << " is: (" << position[0] << "; " << position[1] << ").\n ";
//}