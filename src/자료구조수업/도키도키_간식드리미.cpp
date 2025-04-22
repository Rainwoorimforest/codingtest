#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N;
	int now = 1;
	bool flag = true;
	queue<int> q;
	stack<int> st;
	vector<int> v;

	cin >> N;

	//입력받기
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		q.push(a);
	}

	//본문

	while (v.size() < N)
	{
		if (!(q.empty()))
		{
			if (now == q.front()) //#1
			{
				v.push_back(q.front());
				q.pop();

				now++;

			}
			else
			{
				if (!(st.empty()) && now == st.top())//#2
				{
					v.push_back(st.top());
					st.pop();

					now++;
					continue;
				}

				st.push(q.front()); //#3
				q.pop();

			}
		}
		else //큐가 빌 때
		{
			while (!(st.empty()))
			{
				v.push_back(st.top());
				st.pop();
			}

			break;
		}



	}

	for (int i = 0; i <= v.size() - 2; i++)
	{
		if (v[i] > v[i + 1])
		{
			flag = false;
			break;
		}
	}

	//출력
	if (flag) cout << "Nice" << endl;
	else cout << "Sad" << endl;




	return 0;

}
