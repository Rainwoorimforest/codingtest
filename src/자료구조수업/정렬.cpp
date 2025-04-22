#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

// 1.버블 정렬

/*
int main() {
	int N;
	vector <int> bubble;
	cin >> N;

	
	//입력 받기
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		bubble.push_back(a);
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			cout << i << "번째 루프: " << endl;
			if (bubble[j-1] > bubble[j])
			{
				int temp = bubble[j - 1];
				bubble[j - 1] = bubble[j];
				bubble[j] = temp;
			}

		}
	}

	//출력하기
	for (int i = 0; i < N; i++)
	{
		cout << bubble[i] << endl;
	}

	return 0;
}
*/

int main()
{
	string str; //1234
	vector<int> selection_sort;

	cin >> str;

	selection_sort.resize(str.size() + 1);

	//cout << str.substr(0, 1); // 1
	//cout << str.substr(1, 1); // 2
	//cout << str.substr(2, 1); // 3
	
	int N = str.size();//str.size() 4

	//1. string으로 입력 받아 하나씩 문자를 분리 후, int형으로 바꿔 벡터에 할당
	for (int i = 0; i < str.size(); i++) 
	{
		selection_sort[i + 1] = stoi(str.substr(i, 1));
	}

	//2. 정렬 - 선택 정렬
	for (int i = 1; i <= N; i++)
	{
		int max = i;
		for (int j = i+1; j <= N; j++) // 최댓값 구하기
		{
			if (selection_sort[max] < selection_sort[j]) max = j;
		}

		if (selection_sort[i] < selection_sort[max])
		{
			int temp = selection_sort[i];
			selection_sort[i] = selection_sort[max];
			selection_sort[max] = temp;
		}
	}

	//출력하기
	for (int i = 1; i <= N; i++)
	{
		cout << selection_sort[i];
	}

	return 0;
}