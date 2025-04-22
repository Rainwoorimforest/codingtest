#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	bool flag=true;
	queue<int> q;

	cin >> N;

	//큐에 입력
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	//본문
	while (q.size() != 1)
	{
		if (!(q.empty()))
		{
			//맨 앞장 버리기
			q.pop();
			//앞장 -> 맨 뒤 섞기

			int a;
			a = q.front();
			q.pop();
			q.push(a);
		}
	}

	//출력
	cout << q.front() << endl;

	return 0;
}