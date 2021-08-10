#include <iostream>
using namespace std;

long long factorial(long long a) 
{
	if (a == 0 || a == 1) return 1;
	return a * factorial(a - 1);
}

int main() 
{
	long long a;
	do {
		cout << "Unsigned int number input: ";
		cin >> a;
		if (a < 0) cout << "Wrong! Type again.\n";
		else cout << "Result: " << factorial(a);
	} while (a < 0);
}