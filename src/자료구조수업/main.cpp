#include <iostream>
using namespace std;

int main() {

	int x , a;
	cout << "x���� �Է��ϼ���:";
	cin >> x;

	cout << "a���� �Է��ϼ���:";
	cin >> a;

	switch (a)
	{
	case 1: x += 5;
		cout << x <<endl;
		break;
	case 2: x += 10;
		cout << x << endl;
		break;
	case 3: x += 16;
		cout << x << endl;
		break;
	case 4: x += 34;
		cout << x << endl;
		break;
	default: cout << "���ϴ� a���� �ƴմϴ�." << endl;
	}

	return 0;




}
