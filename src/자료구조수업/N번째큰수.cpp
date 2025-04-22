#include <iostream>
#include <queue>

using namespace std;

int main() {

	//N번째 '큰'수 구하기 -> greater
	//N번째 '작은수' 구하기 -> less
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			pq.push(num);
			
			if (pq.size() > N)
			{
				pq.pop();
			}

		}
	}

	cout << pq.top();

	return 0;
}