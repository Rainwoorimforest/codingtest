#include <iostream>
#include <queue>
#include <vector>


using namespace std;


struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b)) return a > b; //두 수의 절댓값이 같을 때, a가 크면 true반환
		else return abs(a) > abs(b); //두 수의 절댓값을 비교하여 a가 크면 true을 반환
	}
};

int main() {
	int N;

	//cin >> N;

	priority_queue<int, vector<int>, compare> pd;

	pd.push(2);
	cout << "push:2, 현재 top은 "<< pd.top()<<endl;

	pd.push(-2);
	cout << "push:-2, 현재 top은 " << pd.top() << endl;

	pd.push(3);
	cout << "push:3, 현재 top은 " << pd.top() << endl;

	pd.push(4);
	cout << "push:4, 현재 top은 " << pd.top() << endl;

	pd.push(3);
	cout << "push:3, 현재 top은 " << pd.top() << endl;

	pd.push(5);
	cout << "push:5, 현재 top은 " << pd.top() << endl;

	cout << "--------------------------------------------" << endl;
	cout << "pop연산 수행 후 top은: " << endl;
	pd.pop();

	cout << pd.top();

}