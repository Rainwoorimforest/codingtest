#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N;
    string s;
    vector<int> result;

    queue<int> q;

    cin >> N;

    for(int i=0; i < N; i++)
    {
        int a;
        cin >> s;

        if ( s == "push")
        {
            cin >> a;
            q.push(a);
        }
        else if( s == "pop")
        {
            if(q.empty())
            {
                result.push_back(-1);
                continue;
            } 
            result.push_back(q.front());
            q.pop();
        }
        else if( s == "size")
        {
            result.push_back(q.size());
        }
        else if( s == "empty")
        {
            if(q.empty())
            {
                result.push_back(1);
                continue;
            }

            result.push_back(0);
        }
        else if ( s== "front")
        {
            if(q.empty())
            {
                result.push_back(-1);
                continue;
            }

            result.push_back(q.front());
        }
        else if(s == "back")
        {
            if(q.empty())
            {
                result.push_back(-1);
                continue;
            }

            result.push_back(q.back());
        }
        

    }

    for(int i=0; i < result.size(); i++)
    {
            cout<<result[i]<<endl;
    }
    
}