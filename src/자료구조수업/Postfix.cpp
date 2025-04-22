#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

	int N;
	string s;
	stack<float> st;
	vector<int> v;
	

	cin >> N;
	cin >> s;

	v.resize(N);
	int s_size = s.size();
	//�ǿ����� �ޱ�
	for (int i = 0; i < N; i++)
	{
		cin >> v[i]; //�̰� ��?????
	}

	//������ ������ ���
	for (int i = 0; i < s_size; i++) 
	{
		

		if (s.at(i) >= 42 && s.at(i) <= 47)
		{
			float num1, num2,result;
			num1 = st.top();
			st.pop();
			num2 = st.top();
			st.pop();

			if (s.at(i) == '*') 
			{
				result = num1 * num2;
				st.push(result);
			}
			else if (s.at(i) == '+')
			{
				result = num1 + num2;
				st.push(result);
			}
			else if (s.at(i) == '-')
			{
				result = num2 - num1;
				st.push(result);
			}
			else if (s.at(i) == '/')
			{
				result = num2 / num1;
				st.push(result);
			}
			

		}
		else if(s.at(i)>=65 && s.at(i)<=90) 
		{
			st.push((float)v[s.at(i) - 'A']); // ���� ����Ʈ
			
		}
		
	}
	//�� ���
	cout <<fixed<<setprecision(2)<< st.top() << endl;

	return 0;
}