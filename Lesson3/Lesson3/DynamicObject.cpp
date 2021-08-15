#include "DynamicObject.h"
DynamicObject::DynamicObject() {}
DynamicObject::DynamicObject(int _oid, string _name, float _posX, float _posY) {
	this->oid = _oid;
	this->name = _name;
	this->position[0] = _posX;
	this->position[1] = _posY;
}
//int dynamicobject::getId() {
//	return this->oid;
//}
//string dynamicobject::getName() {
//	return this->name;
//}
//void dynamicobject::move(float _x, float _y) {
//	position[0] = _x;
//	position[1] = _y;
//}
//void dynamicobject::printPosition() {
//	cout << "position of " << getname() << " is: (" << position[0] << "; " << position[1] << ").\n ";
//}