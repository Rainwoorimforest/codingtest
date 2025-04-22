#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	int N, num;
	vector<int> v;

	cin >> N;
	
	num = N * N;
	//vector에 입력값 모두 받기
	for (int j = 0; j < num; j++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		
	}
	
	priority_queue<int,vector<int>,greater<int>> pq;

	//N번째 큰 수 찾기
	for (int i = 0; i < num; i++) //0~24 index
	{
		if (pq.empty() || pq.size() < N)
		{
			pq.push(v[i]);
		}
		else if (pq.size() == N)
		{
			if (pq.top() < v[i]) //넣을려는 v[i]값 < root
			{
				pq.pop();
				pq.push(v[i]);
			}
		}
	}

	//출력
	cout << pq.top() << endl;


	
	return 0;

}