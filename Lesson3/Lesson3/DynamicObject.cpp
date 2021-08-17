#include "DynamicObject.h"
DynamicObject::DynamicObject() {}
DynamicObject::DynamicObject(int _oid, string _name, float _posX, float _posY) : BaseObject(_oid, _name, _posX, _posY) {
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