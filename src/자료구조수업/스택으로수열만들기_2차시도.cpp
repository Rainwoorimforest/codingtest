#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int N,copy_num;
	int j = 0; //vector index
	int k = 1; //temp_st�� �� ��������
	vector<int> v;
	vector<string> result_v;
	stack<int> temp_st;
	//stack<int> result_st;
	

	cin >> N; //�Է� 1. �׽�Ʈ ���̽� N �Է¹ޱ�

	//�Է� 2. 8���� input �Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	//ù��° ���
	temp_st.push(k);
	k++;
	//cout << "+" << endl;
	result_v.push_back("+");
	
	while (temp_st.empty() || v[j] >= temp_st.top()) //���⼭ �����߻�.
	{
		// v[j] > temp_st.top() �� ��
			if (v[j] > temp_st.top())
			{
				temp_st.push(k);
				k++;
				//cout << "+" << endl;
				result_v.push_back("+");

				continue;
			}


			// v[j] = temp_st.top() �� ��
			temp_st.pop();
			//cout << "-" << endl;
			result_v.push_back("-");

			if (v[j] == v[N - 1]) //�������� �� �� ������
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


	//��� ����ϱ� ->  "NO"�� ��쿡�� ���α׷� ������� �ʰ� ���ʱ��� ����.

	

	cout << "NO" << endl;

	
	


}

