
#include <iostream>
#include <queue>

using namespace std;

int main() {

	
	int N;
	int temp;
	queue<int> q;

	cin >> N;

	// ť�� ī�� �ֱ�
	for (int i = 0; i < N; i++)
	{
		q.push(i+1); 
	}

	while (q.size() != 1)
	{
		
		q.pop(); //1. �� �� ��� ����

		temp = q.front(); //1. �� �� ��� temp�� ���� �� �� �ڷ� ������
		q.pop();
		q.push(temp);
	}

	cout << q.front() << endl;
	
	
	return 0;
}
