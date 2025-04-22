#include <iostream>
#include <queue>
#include <vector>


using namespace std;


struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b)) return a > b; //�� ���� ������ ���� ��, a�� ũ�� true��ȯ
		else return abs(a) > abs(b); //�� ���� ������ ���Ͽ� a�� ũ�� true�� ��ȯ
	}
};

int main() {
	int N;

	//cin >> N;

	priority_queue<int, vector<int>, compare> pd;

	pd.push(2);
	cout << "push:2, ���� top�� "<< pd.top()<<endl;

	pd.push(-2);
	cout << "push:-2, ���� top�� " << pd.top() << endl;

	pd.push(3);
	cout << "push:3, ���� top�� " << pd.top() << endl;

	pd.push(4);
	cout << "push:4, ���� top�� " << pd.top() << endl;

	pd.push(3);
	cout << "push:3, ���� top�� " << pd.top() << endl;

	pd.push(5);
	cout << "push:5, ���� top�� " << pd.top() << endl;

	cout << "--------------------------------------------" << endl;
	cout << "pop���� ���� �� top��: " << endl;
	pd.pop();

	cout << pd.top();

}