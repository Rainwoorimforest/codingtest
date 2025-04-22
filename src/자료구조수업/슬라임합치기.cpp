#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;
	int max_sum = 0;
	//vector<int> v;

	cin >> N;

	priority_queue<int, vector<int>, less<int>> pq; //�ִ������� ����

	//N���� ������ ũ�� �� �����ϱ�
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}
	
	while (!(pq.size() == 1)) //pq�� size�� 1�� �ƴ� �� // while (!pq.size() == 1) ��ȣ ����
	{
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		
		max_sum += (x * y);

		pq.push(x + y);

		if (pq.size() == 1)
		{
			cout << max_sum << endl;
		}

	}

	
	return 0;
}
