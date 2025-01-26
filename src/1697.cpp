// 일단 이게 어떻게 dfs bfs 문제인지 눈치를 채는거죠?
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> adj;
static vector<bool> visited;

void BFS();

int main()
{
    int N, K; 
    cin >> N >> K;

    printf("d설연휴 쉴게여~~22");
    
}

void BFS(int n){

    queue<int> q;
    q.push(n);

    visited[n] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int i: adj[now])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    
}