/*
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;


/*
����
- T: �׽�Ʈ ������ ���� ����
- s : string ������ �Է� ���� ����
- stack<char> st: '('�� ���� ���� (�迭)

���̵��
1. ���ÿ��� '('�� �ִ´�.
2. ')'�� ������ ���ÿ� top�� �����Ѵ�.
3. ������ �ƹ��͵� ���� YES, �ƴϸ� NO

for�� T��{

if ( '('�� ���ÿ� �ֱ�)
else ( '(' ���ÿ��� ���� )

}

if (������ ������� YES)
else (NO)
*/

/*


int main() {
	int T;
	stack<char> st_input;
	queue<string> q;
	string s;

	cin >> T;
	
	// �Է� ��� �ޱ�

	
	for (int i = 0; i < T; i++)
	{
		char temp;
		if(s.at(i) == '(' || s.at(i) == ')') 
		{
			temp; //string �߰�
			st_input.push(s); //���� �� ������ string �ϳ�
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
			else if (ch == ')') // ( �Ǵ� )�� �ƴ� ���ɼ��� ����ΰ� else if�� ��.
			{
				if (st_input.empty())
				{
					success = false;
					break;
				} //empty r�˻縦 ���� �ϰ�����.
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

		// ����
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

