//자료구조 실습 13주차 과제
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

int main()
{
	int N;
	int check = 0;
	vector<int> bubble;
	vector<int> pre_sorted;
	vector<int> index_before;
	vector<int> result;

	cin >> N;
	
	bubble.resize(N + 1);
	pre_sorted.resize(N + 1);
	index_before.resize(N + 1);
	result.resize(N + 1);


	//입력받기
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		bubble[i] = a;
		pre_sorted[i] = a;
	}


	sort(pre_sorted.begin()+1, pre_sorted.end());


	//버블 정렬 
	for (int i = 1; i < N; i++)
	{
		for (int k = 1; k <= N; k++) { //병렬 전, 인덱스 값 구하기
			int compare = pre_sorted[k];
			auto it = find(bubble.begin() + 1, bubble.end(), compare);
			//cout << "compare: "<<compare << endl;
			if (it != bubble.end()) {
				index_before[k] = distance(bubble.begin(), it);
			}
		}

		for (int j = 1; j < N; j++)
		{

			if (bubble[j - 1] > bubble[j])
			{
				int temp = bubble[j - 1];
				bubble[j - 1] = bubble[j];
				bubble[j] = temp;
			}


		}

		for (int l = 1; l <= N; l++) //정렬 후, index값끼리 차이 구하기
		{
			result[l] = index_before[l] - l;

			check = max(check, result[l]);
			/*
			if (l = N)
			{
				check = *max_element(result.begin() + 1, result.end());
				cout << i << "번 loop에서 버블 정렬 시, check: " << check << endl;
				if (check+1 == 2) //확인해야 할 것: check==1이면 해당 loop에서 모두 정렬이 됐다는 의미인가?
					break;
			}
			*/
			
		}	
	}

	cout << check + 1;

	return 0;
}