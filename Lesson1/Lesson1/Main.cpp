#include <iostream>
using namespace std;

void swap1(int& _a, int& _b) {
	int tmp = _a;
	_a = _b;
	_b = tmp;
}

void swap2(int* _a, int* _b) {
	int tmp = *_a;
	*_a = *_b;
	*_b = tmp;
}

int main() {
	int a, b;
	cout << "Input 2 numbers: ";
	cin >> a >> b;
	// swap1(a, b);
	swap2(&a, &b);
	cout << "New value after swapping: a = ";
	cout << a << " and b = " << b;
	return 1;
}