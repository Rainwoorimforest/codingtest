#include <iostream>
#include <string>
using namespace std;

int main() {

	char a[5] = { 'H', 'e', 'l', 'l', 'o' };

	char b[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	char c[] = "Hello";

	cout << a << endl << b << endl << c;

	return 0;
}