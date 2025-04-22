#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int solution(priority_queue<int, vector<int>, greater<int>> pq, int K, int &j) { // pq 정의한 그래도 똑같이 해야 함. priority_queue<int, vector<int>, greater<int>> pq_q;

	while (!(pq.empty()) && pq.top() <= K) //복습 포인트. 예외 처리 empty는 꼭 넣어줘야 하는가?
	{
		j++;

		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();

		int level = x + (y * 2);
		pq.push(level);

		if (pq.top() >= K) // 종결조건1. 스코빌 지수를 K이상으로 만들었을 때, 최소값
		{
			cout << j << endl;
			break;
		}

		if (pq.size() == 1) //종결조건2. 스코빌 지수를 K이상 만들지 못하고 프로그램 종료
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

	priority_queue<int, vector<int>, greater<int>> pq_q; //greater는 루트로부터 커지는 최소heap
	
	//pq에 맵기 정렬하기
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