#include<iostream>
#include<stack>
using namespace std;

int precedence(char ch)
{ 
	if (ch == '(') // ( 일 때
	{
		return 0;
	}
	if (ch == '+' || ch == '-') // 연산자 ( +, - )일 때
	{
		return 1;
	}
	else // 연산자 ( *, / )일 때
	{
		return 2;
	}
}


int main() {
	string infix; 
	cin >> infix;

	string posfix; // 후위표기법(결과)

	stack <char> s; // 괄호 및 연산자 담기

	for (char ch : infix) {
		if ('A' <= ch && ch <= 'Z') // 알파벳을 만났을 때
		{
			posfix += ch; 
		}
		else if (ch == '(') // (일 때
		{
			s.push(ch);
		}
		else if (ch == ')') // )일 때
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