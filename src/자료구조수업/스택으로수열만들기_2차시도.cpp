#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int N,copy_num;
	int j = 0; //vector index
	int k = 1; //temp_st에 들어갈 오름차수
	vector<int> v;
	vector<string> result_v;
	stack<int> temp_st;
	//stack<int> result_st;
	

	cin >> N; //입력 1. 테스트 케이스 N 입력받기

	//입력 2. 8개의 input 입력받기
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	//첫번째 경우
	temp_st.push(k);
	k++;
	//cout << "+" << endl;
	result_v.push_back("+");
	
	while (temp_st.empty() || v[j] >= temp_st.top()) //여기서 오류발생.
	{
		// v[j] > temp_st.top() 일 때
			if (v[j] > temp_st.top())
			{
				temp_st.push(k);
				k++;
				//cout << "+" << endl;
				result_v.push_back("+");

				continue;
			}


			// v[j] = temp_st.top() 일 때
			temp_st.pop();
			//cout << "-" << endl;
			result_v.push_back("-");

			if (v[j] == v[N - 1]) //마지막일 때 및 결과출력
			{
				for (int i = 0; i < result_v.size(); i++)
				{
					cout << result_v[i] << endl;

					if (i == result_v.size() - 1)
					{
						return 0;
					}
				}
			}

			j++;

	}


	//결과 출력하기 ->  "NO"일 경우에만 프로그램 종료되지 않고 이쪽까지 들어옴.

	

	cout << "NO" << endl;

	
	


}

