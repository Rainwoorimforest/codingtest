#include <iostream>
#include <queue>


using namespace std;


//���߿켱����ť ����
int main() {

	int N,min,max;
	int cnt = 0;

	cin >> N;

	priority_queue<int, vector<int>, less<int>> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;


	for (int i = 0; i < N; i++)
	{
		char oper;
		int num;
		cin >> oper >> num;

		switch (oper)
		{
		case 'I':
		{
			maxheap.push(num);
			minheap.push(num);
			cnt++;
			break; //����
		}
		case 'D':
		{
			if (cnt > 0)
			{
				if (num == -1) minheap.pop();
				else maxheap.pop();
				cnt--;
			}
			break; //���� �� ť �����͸� �����϶�� ������ �� �����ϴ� break;
		}
		default: break;
		}
	}

	//���
	if (cnt == 0) min = max = 0;
	else
	{
		min = minheap.top();
		max = maxheap.top();
	}

	cout << "[" << max<< "," << min << "]" << endl;

}