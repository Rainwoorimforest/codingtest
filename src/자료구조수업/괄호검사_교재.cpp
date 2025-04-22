#include <iostream> 
#include <stack>
#include <string>

using namespace std;


int main()
{
    int N;
    string s;
    stack<char> st;

    cin >> N;
    for (int i = 0; i < N; i++)	 // N개의 데이터
    {
        bool success = true;	// success 변수 초기화
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            char ch = s.at(j);
            if (ch == '(') st.push(ch);
            else if (ch == ')')
            {
                if (st.empty()) { success = false; break; }
                else if (st.top() == '(') st.pop();
                else { success = false; break; }
            }
        }
        if (success && st.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
        while (!st.empty()) st.pop();  // initialize stack
    }
}