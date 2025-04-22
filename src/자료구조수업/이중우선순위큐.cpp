#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

/*
solution �Լ�
- ���ڿ��� �Ѳ����� �Է¹޾� I����� D������ �Ѵ�.
- ��ȯ��: string ����
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
		istringstream steam(st); //���ڿ� �Ľ��� ����. //istringstream�� ��ü steam ���� 
		
		steam >> word; //word��� string�� ���ڿ� �Ҵ�

		//operation ����
		if (word == "I") //insert //����ó���� ���?
		{
			steam >> word;

			pq1.push(stoi(word));
			pq2.push(stoi(word));

			left_node++;

		}

		else if (word == "D") //remove //remove �ϱ� ���� pop ����ó�� ����!
		{
			steam >> word;
	
			/*
			�ּ���: 1 3/ 6 8 100
			�ִ���: 100 9 6/ 3 1

			�ִ���,�ּ����� ���� ��������� ������ ������ ���������� ���� ��
			�ذ�: ���� ���� ���� cnt�� ��������. -> insert�� remove�� �ݿ��Ͽ� 

			*/

			if (word == "1") //ť���� �ִ� ����
			{
				if (!(pq1.empty()))
				{
					pq1.pop();
					left_node--;
				}

			}
			else if (word == "-1") //ť���� �ּڰ� ����
			{
				if (!(pq2.empty()))
				{
					pq2.pop();
					left_node--;
				}
			}
		}
		
	}


	//��� ��ȯ�ϱ�
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
	int N; //�׽�Ʈ ���̽�.���ڿ� ����
	vector<string> st_v;
	vector<int> result_v;

	cin >> N;
	cin.ignore(); // ���� ����Ʈ

	//�Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		string s;
		getline(cin, s); //���鵵 �Է��� ����. ���͸� ġ�� �Է��� ����.
		
		st_v.push_back(s);
	}

	result_v = solution(st_v);


	//��� ����ϱ�
	for (int i = 0; i < 2; i++)
	{
		cout << result_v[i] << " ";
	}
	


	return 0;
}

