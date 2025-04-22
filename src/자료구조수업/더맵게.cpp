#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int solution(priority_queue<int, vector<int>, greater<int>> pq, int K, int &j) { // pq ������ �׷��� �Ȱ��� �ؾ� ��. priority_queue<int, vector<int>, greater<int>> pq_q;

	while (!(pq.empty()) && pq.top() <= K) //���� ����Ʈ. ���� ó�� empty�� �� �־���� �ϴ°�?
	{
		j++;

		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();

		int level = x + (y * 2);
		pq.push(level);

		if (pq.top() >= K) // ��������1. ���ں� ������ K�̻����� ������� ��, �ּҰ�
		{
			cout << j << endl;
			break;
		}

		if (pq.size() == 1) //��������2. ���ں� ������ K�̻� ������ ���ϰ� ���α׷� ����
		{
			return -1;
		}

	}
}

int main() {

	int N,K;
	int j = 0;
	vector<int> scoville;

	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq_q; //greater�� ��Ʈ�κ��� Ŀ���� �ּ�heap
	
	//pq�� �ʱ� �����ϱ�
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		pq_q.push(a);
	}

	cin >> K;

	solution(pq_q, K, j);

	return 0;
}