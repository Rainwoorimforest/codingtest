#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, amx;
	int cnt = 0;
	int seq[100001];

	queue<int> q;
	queue<char> result;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		result.push('+');

		// ���Ͱ� ��������ʰ�,  cnt��° ������ ť�� ������ ���ҿ� �������
		while (!q.empty() && q.back() == seq[cnt])
		{
			q.pop();
			result.push('-');
			cnt++;
		}
	}

	if (!q.empty())
	{
		cout << "NO" << endl;
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			
		}
	}
}