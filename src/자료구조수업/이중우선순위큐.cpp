#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

/*
solution 함수
- 문자열을 한꺼번에 입력받아 I연산과 D연산을 한다.
- 반환형: string 벡터
*/
vector<int> solution(vector<string> operations)
{
	priority_queue<int, vector<int>, less<int>> pq1; //max heap
	priority_queue<int, vector<int>, greater<int>> pq2; //min heap
	int vector_size = operations.size();
	int left_node = 0;
	vector<int> result_v;


	for (int i = 0; i < vector_size; i++)
	{
		string st = operations[i];
		string word;
		istringstream steam(st); //문자열 파싱을 위함. //istringstream의 객체 steam 생성 
		
		steam >> word; //word라는 string에 문자열 할당

		//operation 연산
		if (word == "I") //insert //예외처리는 어떻게?
		{
			steam >> word;

			pq1.push(stoi(word));
			pq2.push(stoi(word));

			left_node++;

		}

		else if (word == "D") //remove //remove 하기 전에 pop 예외처리 조심!
		{
			steam >> word;
	
			/*
			최소힙: 1 3/ 6 8 100
			최대힙: 100 9 6/ 3 1

			최대힙,최소힙이 각각 비어있지도 않지만 실제론 남아있을게 없을 때
			해결: 노드들 개수 변수 cnt를 만들어야함. -> insert와 remove를 반영하여 

			*/

			if (word == "1") //큐에서 최댓값 삭제
			{
				if (!(pq1.empty()))
				{
					pq1.pop();
					left_node--;
				}

			}
			else if (word == "-1") //큐에서 최솟값 삭제
			{
				if (!(pq2.empty()))
				{
					pq2.pop();
					left_node--;
				}
			}
		}
		
	}


	//결과 반환하기
	if (left_node <= 0)
	{
		result_v.push_back(0);
		result_v.push_back(0);
		
		return result_v;
	}
	else
	{
		result_v.push_back(pq1.top());
		result_v.push_back(pq2.top());

		return result_v;
	}

	
}


int main() {
	int N; //테스트 케이스.문자열 개수
	vector<string> st_v;
	vector<int> result_v;

	cin >> N;
	cin.ignore(); // 복습 포인트

	//입력받기
	for (int i = 0; i < N; i++)
	{
		string s;
		getline(cin, s); //공백도 입력을 받음. 엔터를 치면 입력이 끝남.
		
		st_v.push_back(s);
	}

	result_v = solution(st_v);


	//결과 출력하기
	for (int i = 0; i < 2; i++)
	{
		cout << result_v[i] << " ";
	}
	


	return 0;
}

