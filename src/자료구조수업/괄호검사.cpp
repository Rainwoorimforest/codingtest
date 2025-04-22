#include <iostream> 
#include <stack>
#include <string>

using namespace std;


int main() {
	int T; 
	string str;
	stack<char> st;
	//stack<string> st;
	stack<string> result; //����� ���� stack
	// bool success = true;
	
	cin >> T;
	cin.ignore();

	//stack�� ��ȣ �ֱ� �� �˻�
	for (int i = 0; i < T; i++)
	{
		bool success = true; //�߿�
		//getline(cin, str);
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			if (str.at(j) == '(') { st.push('('); }
			else if (str.at(j) == ')') 
			{
				
				if (st.empty()) //����ó�� ����
				{
					success = false;
					break;
				}
				
				/*
				else if (st.top() == ')') //�� �ʿ䰡 ���� �˻�. //st���ÿ��� ���� ��ȣ�� �����ϵ��� �ϴ°� ���̵���̴�.
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

		if (!st.empty()) {  // �� ������ �߰��Ͽ� ������ ��� ���� ������ success�� false�� �����մϴ�.
			success = false;

		}

		if (success && st.empty()) { result.push("YES"); } //string�� ��, "YES". char�� ��, 'YES'�� �ƴ϶� ���� ����.
		else { result.push("NO"); }

		//�� �ʱ�ȭ�ϱ�!
		while (!st.empty()) { st.pop(); }
		
	}



	//��� ���
	/*
	
	for �������� result.size()�� ����Ͽ� ����� ����ϴ� ����� ������ ����ŵ�ϴ�.
	�ֳ��ϸ� result.pop()�� 
	ȣ���� ������ result.size()�� ���� �����ϱ� �����Դϴ�
	
	for (int i = 0; i < result.size(); i++)
	{

		//cout << result.pop() << endl;
		// �ɰ���	�ڵ�	����	������Ʈ	����	��	��ǥ�� ����(Suppression) ����
		//����(Ȱ��)	E0349	�̷��� �ǿ����ڿ� ��ġ�ϴ� "<<" �����ڰ� �����ϴ�.�ڱ���1W_����, ť	C : \Users\yiuri\source\repos\�ڱ���1W_����, ť\�ڱ���1W_����, ť\��ȣ�˻�.cpp	53
		cout << result.top() << endl;
		result.pop(); //�Ųٷ� ���� ��.
	}
	*/

	while (!result.empty())
	{
		cout << result.top() << endl;
		result.pop();
	}


}
