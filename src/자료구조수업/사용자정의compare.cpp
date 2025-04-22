#include<iostream>
#include<vector>
#include<queue>
#include<cmath> //abs()절댓값함수를 위한 라이브러리

using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{	
		//b가 비교연산
		//true -> 자리바꿈. false -> 그대로. upheap 종료
		//결과물을 먼저 생각하고, 
		if (abs(a) == abs(b)) return a > b; //내림차순
		else return abs(a) > abs(b);
	}
};

int main() {
	int N;
	int i = 0;
	vector<int> v;

	cin >> N;

	priority_queue<int, vector<int>, compare> pq;

	while (i < N)
	{
		int a;
		cin >> a;
		
		if (a == 0) //절댓값이 가장 작은 값 출력 후 제거
		{
			if (!(pq.empty()))
			{
				v.push_back(pq.top());
				pq.pop();

				i++;
				continue;
			}
			v.push_back(0);
		}
		else if (a != 0) // pq에 삽입연산
		{
			pq.push(a);
		}
		i++;
	}

	//출력하기
	cout << "결과: " << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}


