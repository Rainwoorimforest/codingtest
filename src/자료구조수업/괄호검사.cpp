#include <iostream> 
#include <stack>
#include <string>

using namespace std;


int main() {
	int T; 
	string str;
	stack<char> st;
	//stack<string> st;
	stack<string> result; //결과를 넣을 stack
	// bool success = true;
	
	cin >> T;
	cin.ignore();

	//stack에 괄호 넣기 및 검사
	for (int i = 0; i < T; i++)
	{
		bool success = true; //중요
		//getline(cin, str);
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			if (str.at(j) == '(') { st.push('('); }
			else if (str.at(j) == ')') 
			{
				
				if (st.empty()) //예외처리 조건
				{
					success = false;
					break;
				}
				
				/*
				else if (st.top() == ')') //할 필요가 없는 검사. //st스택에는 여는 괄호만 존재하도록 하는게 아이디어이다.
				{
					success = false;
					break;
				}
				*/
				else if (st.top() == '(')
				{
					st.pop();
				}
				else {
					success = false;
					break;
				}
				
				

			}
			
			
		}

		if (!st.empty()) {  // 이 조건을 추가하여 스택이 비어 있지 않으면 success를 false로 설정합니다.
			success = false;

		}

		if (success && st.empty()) { result.push("YES"); } //string일 때, "YES". char일 때, 'YES'이 아니라 단일 문자.
		else { result.push("NO"); }

		//꼭 초기화하기!
		while (!st.empty()) { st.pop(); }
		
	}



	//결과 출력
	/*
	
	for 루프에서 result.size()를 사용하여 결과를 출력하는 방식은 문제를 일으킵니다.
	왜냐하면 result.pop()을 
	호출할 때마다 result.size()의 값이 감소하기 때문입니다
	
	for (int i = 0; i < result.size(); i++)
	{

		//cout << result.pop() << endl;
		// 심각도	코드	설명	프로젝트	파일	줄	비표시 오류(Suppression) 상태
		//오류(활성)	E0349	이러한 피연산자와 일치하는 "<<" 연산자가 없습니다.자구실1W_스택, 큐	C : \Users\yiuri\source\repos\자구실1W_스택, 큐\자구실1W_스택, 큐\괄호검사.cpp	53
		cout << result.top() << endl;
		result.pop(); //거꾸로 나올 것.
	}
	*/

	while (!result.empty())
	{
		cout << result.top() << endl;
		result.pop();
	}


}
