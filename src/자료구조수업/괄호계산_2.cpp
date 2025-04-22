/*
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;


/*
변수
- T: 테스트 데이터 개수 변수
- s : string 형식의 입력 받을 변수
- stack<char> st: '('을 받을 스택 (배열)

아이디어
1. 스택에는 '('만 넣는다.
2. ')'가 나오면 스택에 top을 제거한다.
3. 마지막 아무것도 없음 YES, 아니면 NO

for문 T번{

if ( '('면 스택에 넣기)
else ( '(' 스택에서 제거 )

}

if (스택이 비어있음 YES)
else (NO)
*/

/*


int main() {
	int T;
	stack<char> st_input;
	queue<string> q;
	string s;

	cin >> T;
	
	// 입력 모두 받기

	
	for (int i = 0; i < T; i++)
	{
		char temp;
		if(s.at(i) == '(' || s.at(i) == ')') 
		{
			temp; //string 추가
			st_input.push(s); //스택 한 공간에 string 하나
		}
	}
	*/

	/*
	for (int i = 0; i < T; i++)
	{
		bool success = true;
		
		

		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			char ch = s.at(j);
			if (ch == '(') { st_input.push(ch); }
			else if (ch == ')') // ( 또는 )가 아닐 가능성을 열어두고 else if라 함.
			{
				if (st_input.empty())
				{
					success = false;
					break;
				} //empty r검사를 먼저 하게하자.
				else if (st_input.top() == '(')
				{
					st_input.pop();
				}
				else
				{
					success = false;
					break;
				}
			}


		}

		// 수정
		if (success && st_input.empty())
		{
			q.push("YES");

		}
		else
		{
			q.push("NO");
		}


		while (!st_input.empty())
		{
			st_input.pop();
		}

		if (success && st_input.empty()) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}

	for (int i = 0; i < q.size(); i++)
	{
		string a = q.front();
		cout << a << endl;

	}

	return 0;
}
*/

