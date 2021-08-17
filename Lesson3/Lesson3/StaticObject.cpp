#include "StaticObject.h"
StaticObject::StaticObject() {}
StaticObject::StaticObject(int _oid, string _name, float _posX, float _posY) : BaseObject(_oid, _name, _posX, _posY) {
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