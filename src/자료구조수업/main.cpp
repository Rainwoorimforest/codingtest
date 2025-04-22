#include <iostream>
using namespace std;

int main() {

	int x , a;
	cout << "x값을 입력하세요:";
	cin >> x;

	cout << "a값을 입력하세요:";
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
	default: cout << "원하는 a값이 아닙니다." << endl;
	}

	return 0;




}
