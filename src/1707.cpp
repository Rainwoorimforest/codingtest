#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool Bipartie(vector<vector<int>> grah, int v)
{
    queue<int> q;
    vector<int> color(v+1, 0); //0: 미방문 , 1: 빨, -1: 파

    for(int i=0; i < v; i++)
    {
        if(color[i] != 0) continue;

        q.push(i);
        color[i] = 1; //방문처리

        while(!q.empty())
        {
            int now = q.front();
            q.pop();

            for(int j : grah[now])
            {
                
                if(color[j] == 0) //미방문
                {
                    color[j] = -color[now];
                    q.push(j);
                }
                else if(color[j] == color[now]) //다른색
                {
                    return false;
                }
                
            }


        }

        
       

    }
    

 
    return true;


}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K,V,E;
    

    cin >> K;

    for(int i=0; i < K; i++)
    {
        cin >> V >> E;
        vector<vector<int>> graph(V+1); //크기 설정 안한다면?

        for (int j=0; j < E; j++)
        {
            int v1,v2;
            cin >> v1 >> v2;

            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        
        if(Bipartie(graph, V))
        {
            cout<<"YES"<<'\n';
        }
        else
        {
            cout<<"NO"<<"\n";
        }

        graph.clear();
    }

    return 0;
}

