
#include <iostream>
#include <queue>

using namespace std;

int main() {

	
	int N;
	int temp;
	queue<int> q;

	cin >> N;

	// 큐에 카드 넣기
	for (int i = 0; i < N; i++)
	{
		q.push(i+1); 
	}

	while (q.size() != 1)
	{
		
		q.pop(); //1. 맨 앞 요소 삭제

		temp = q.front(); //1. 맨 앞 요소 temp에 복사 후 맨 뒤로 보내기
		q.pop();
		q.push(temp);
	}

	cout << q.front() << endl;
	
	
	return 0;
}
