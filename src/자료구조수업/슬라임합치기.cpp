#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;
	int max_sum = 0;
	//vector<int> v;

	cin >> N;

	priority_queue<int, vector<int>, less<int>> pq; //최대힙으로 정렬

	//N개의 슬라임 크기 을 정렬하기
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}
	
	while (!(pq.size() == 1)) //pq의 size가 1이 아닐 때 // while (!pq.size() == 1) 괄호 주의
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
