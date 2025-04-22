#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main() {

	int N;
	vector<int> v;
	queue<int> result_q; //결과를 넣은 queue
	cin >> N;
	//v.resize(N);

	priority_queue<int, vector<int>, greater<int>> pq; //greater는 최소힙

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		
		if(a==0) //입력이 0일 때->루트반환 및 삭제. 1.empty일 때 2.아닐 때
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
	
	//결과 출력
	int result_size = result_q.size();
	for (int i = 0; i < result_size; i++)
	{
		cout << result_q.front() << endl;
		result_q.pop();
	}



	return 0;
}