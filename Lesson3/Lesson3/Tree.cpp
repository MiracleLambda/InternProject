#include "Tree.h"
Tree::Tree() {}
Tree::~Tree() {}
Tree::Tree(int _oid, string _name, float _posX, float _posY) : StaticObject(_oid, _name, _posX, _posY) {
}
int Tree::getId() {
	return this->oid;
}
string Tree::getName() {
	return this->name;
}
void Tree::move(float _x, float _y) {
	cout << getName() << " can't move.\n";
}
void Tree::printPosition() {
	cout << "\tPosition of " << getName() << " is: (" << posX << ", " << posY << ").\n";
}