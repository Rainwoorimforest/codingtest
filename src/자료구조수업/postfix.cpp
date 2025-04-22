#include<iostream>
#include<stack>
using namespace std;

int precedence(char ch)
{ 
	if (ch == '(') // ( �� ��
	{
		return 0;
	}
	if (ch == '+' || ch == '-') // ������ ( +, - )�� ��
	{
		return 1;
	}
	else // ������ ( *, / )�� ��
	{
		return 2;
	}
}


int main() {
	string infix; 
	cin >> infix;

	string posfix; // ����ǥ���(���)

	stack <char> s; // ��ȣ �� ������ ���

	for (char ch : infix) {
		if ('A' <= ch && ch <= 'Z') // ���ĺ��� ������ ��
		{
			posfix += ch; 
		}
		else if (ch == '(') // (�� ��
		{
			s.push(ch);
		}
		else if (ch == ')') // )�� ��
		{
			while (!s.empty())
			{
				if (s.top() == '(')
				{
					s.pop();
					break;
				}
				posfix += s.top();
				s.pop();
			}
		}
		else 
		{
			while (!s.empty() && precedence(s.top()) >= precedence(ch))
				
			{
				posfix += s.top();
				s.pop();
			}
			s.push(ch); 
		}
	}

	while (!s.empty()) 
	{
		posfix += s.top();
		s.pop();
	}

	cout << posfix;
	return 0;
}