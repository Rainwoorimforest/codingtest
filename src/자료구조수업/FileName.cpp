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

		// 벡터가 비어있지않고,  cnt번째 수열이 큐의 마지막 원소와 같을경우
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