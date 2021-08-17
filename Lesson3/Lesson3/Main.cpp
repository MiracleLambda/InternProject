#include <iostream>
#include "Tree.h"
#include "House.h"
#include "Motorbike.h"
#include "Car.h"
#include <list>
#include <crtdbg.h>
using namespace std;

int main() {
	{
		list<BaseObject*> bo;

		BaseObject* tree = new Tree(1, "Tree1", 0, 0);
		bo.push_back(tree);

		BaseObject* house = new House(2, "House1", 0, 1);
		bo.push_back(house);

		BaseObject* motorbike = new Motorbike(3, "Motorbike1", 1, 0);
		bo.push_back(motorbike);

		BaseObject* car = new Tree(4, "Car1", 1, 1);
		bo.push_back(car);

		cout << "List of name:\n";
		for (auto obj : bo) {
			cout << "\t" << obj->getName() << endl;
		}

		cout << "List of ID:\n";
		for (auto obj : bo) {
			cout << "\t" << obj->getId() << endl;
		}

		cout << "List of position:\n";
		for (auto obj : bo) {
			obj->printPosition();
		}

		bo.clear();
		delete tree;
		delete house;
		delete motorbike;
		delete car;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}