#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main() {

	int N;
	vector<int> v;
	queue<int> result_q; //����� ���� queue
	cin >> N;
	//v.resize(N);

	priority_queue<int, vector<int>, greater<int>> pq; //greater�� �ּ���

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		
		if(a==0) //�Է��� 0�� ��->��Ʈ��ȯ �� ����. 1.empty�� �� 2.�ƴ� ��
		{
			if (pq.empty())
			{
				result_q.push(0);
			}
			else
			{
				result_q.push(pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(a);
		}
	}
	
	//��� ���
	int result_size = result_q.size();
	for (int i = 0; i < result_size; i++)
	{
		cout << result_q.front() << endl;
		result_q.pop();
	}



	return 0;
}