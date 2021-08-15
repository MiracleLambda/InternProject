#include "Tree.h"
Tree::Tree() {}
Tree::~Tree() {}
Tree::Tree(int _oid, string _name, float _posX, float _posY) {
	this->oid = _oid;
	this->name = _name;
	this->position[0] = _posX;
	this->position[1] = _posY;
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
	cout << "Position of " << getName() << " is: (" << position[0] << ", " << position[1] << ").\n";
}