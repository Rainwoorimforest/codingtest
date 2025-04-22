#include<iostream>
#include<stack>
#include<queue>
#include<vector>

/*
오름차순 대기열 순서대로 라인 통과가능.

입력 받는 대기열번호는 -> 큐

1. 큐 -> 라인 순서대로라면 라인
2. 큐 -> 스택 순서대로가 아니면 웨이팅 스택
2-1. 스택->라인 	스택도 순서가 되면 pop해서 라인


*/

using namespace std;

int main() {
	int N;
	int now = 1;
	bool flag = true;
	queue<int> q;
	stack<int> st;
	vector<int> v;

	cin >> N;

	//대기열 입력 받기
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		q.push(a);
	}

	//대기열 라인 이동
	while(v.size()<=N)
	{
		if (!(st.empty()) || !(q.empty()))
		{
			//순서 o, 큐 -> 라인
			if (q.front() == now)
			{
				v.push_back(q.front());
				q.pop();

				now++;

			}

			//순서 x, 큐 -> 스택
			else
			{

				//순서가 되면 스택 -> 라인
				if (st.top() == now)
				{
					v.push_back(st.top());
					st.pop();

					now++;
				}

				st.push(q.front());
				q.pop();
			
			}
		}
		
		
	}



	//벡터 오름차순 확인
	for (int i = 0; i < N; i++)
	{
		if (v[i] > v[i + 1])
		{
			flag = false;
			break;
		}
	}

	//출력
	if (flag) { cout << "Nice" << endl; }
	else { cout << "Sad" << endl; }

	return 0;

}
