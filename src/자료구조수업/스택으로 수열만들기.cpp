/*
#include <iostream>
#include <stack>
#include <queue>


using namespace std;

int main() {

	int N, temp;
	int j = 1;
	int b_count = 0;
	int arr[100000];
	//char result[100000];

	stack<int> st_1;
	stack<int> st_2_temp;
	queue<string> result;
	bool success;
	bool success_2 = true;

	//���� �Է� �ޱ�
	cin >> N;


	for (int i = N; i > 0; i--)
	{
		st_2_temp.push(i);
	}

	//�ʱ�ȭ
	// ���ÿ� 1 �߰�
	temp = st_2_temp.top();
	st_2_temp.pop();

	st_1.push(temp);
	result.push("+");
	

	while (b_count < N)
	{

		int b; 

		// ****** ���� �Է¹ޱ� *******
		cin >> b;


		if (b >= st_1.top())
		{
			if (b > st_1.top())
			{
				while (b > st_1.top())
				{
					temp = st_2_temp.top();
					st_2_temp.pop();

					st_1.push(temp);
					result.push("+");

					cout << "������� ���� ��." << endl;
				}
			}
		

			// b = st_1.top()
			st_1.pop();
			result.push("-");

		}
		else
		{
			if (st_1.top() > b)
			{
				success = false; //NO
			
			}
			
			else
			{
				st_1.pop();
				result.push("-");
			}
		}

		
		b_count++;
	}


	cout << "����� ����ϴ� ��" << endl;

	if (success == false)
	{
		cout << "NO" << endl;

	}
	else
	{
		while (!result.empty())
		{
			cout << result.front() << endl;
			result.pop();

		}
	}
	

	cout << "����� ��� ��" << endl;

	return 0;

}
*/