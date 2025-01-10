#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string s;
    vector<int> result;
    stack<int> st;

    cin >> N;

    for(int i=0; i < N; i++)
    {
        cin >> s;

        if ( s == "push" )
        {
            int a;
            cin >> a;
            st.push(a);
        }
        else if( s == "pop" )
        {
            if( st.empty() )
            {
                result.push_back(-1);
                continue;
            }   

            result.push_back(st.top());
            st.pop();
        }
        else if( s == "size" )
        {
            result.push_back(st.size());
        }
        else if( s == "empty" )
        {
            if(st.empty())
            {
                result.push_back(1);
                continue;
            }

            result.push_back(0);
        }
        else if( s== "top" )
        {
            if(st.empty())
            {
                result.push_back(-1);
                continue;
            } 

            result.push_back(st.top());

        }
        
    }


    for(int i=0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}