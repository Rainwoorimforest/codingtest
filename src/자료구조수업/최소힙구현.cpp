#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	//vector<int> v;
	vector<int> answer;

	cin >> N;

	

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		if (a == 0)
		{
			if (!(pq.empty()))
			{
				answer.push_back(pq.top());
				pq.pop();
				continue;
				
			}

			answer.push_back(0);
		}
		else
		{
			pq.push(a);
		}
	}

	//°ª Ãâ·Â
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	return 0;
}
