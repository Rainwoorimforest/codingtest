//�ڷᱸ�� �ǽ� 13���� ����
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


	//�Է¹ޱ�
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		bubble[i] = a;
		pre_sorted[i] = a;
	}


	sort(pre_sorted.begin()+1, pre_sorted.end());


	//���� ���� 
	for (int i = 1; i < N; i++)
	{
		for (int k = 1; k <= N; k++) { //���� ��, �ε��� �� ���ϱ�
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

		for (int l = 1; l <= N; l++) //���� ��, index������ ���� ���ϱ�
		{
			result[l] = index_before[l] - l;

			check = max(check, result[l]);
			/*
			if (l = N)
			{
				check = *max_element(result.begin() + 1, result.end());
				cout << i << "�� loop���� ���� ���� ��, check: " << check << endl;
				if (check+1 == 2) //Ȯ���ؾ� �� ��: check==1�̸� �ش� loop���� ��� ������ �ƴٴ� �ǹ��ΰ�?
					break;
			}
			*/
			
		}	
	}

	cout << check + 1;

	return 0;
}