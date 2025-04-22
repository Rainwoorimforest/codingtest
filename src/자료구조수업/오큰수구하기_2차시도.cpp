#include <iostream>
#include <vector>
#include <queue>

//오큰수: A(i)의 오른쪽에 있는 수 중에서 왼쪽부터 가장 먼저 보이는 수

using namespace std;

int main() {
	int N,compare;
	queue<int> q;

	cin >> N;
	//입력받기
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		q.push(a);
	}

	//오큰수 구하기
	/*
	비교 수: i
	
	*/
	for (int i = 0; i < N; i++)
	{
		compare = q.front();


	}

	return 0;
}