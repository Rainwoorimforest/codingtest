
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> adj; //인접리스트
static vector<bool> visited; //방문 배열
static bool arrive;

void DFS(int node);
void BFS(int node);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,Start;
    arrive=false;

    cin >> N >> M >> Start;
    adj.resize(N+1);

    for(int i = 0; i < M; i++)
    {
        int s,e;
        cin >> s >> e;

        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    //방문할 수 있는 노드가 여러개 이면 번호가 작은 것을 먼저 방문하기 위해 정렬
    for(int i=1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    visited = vector<bool>(N+1,false);

    DFS(Start);
    cout << "\n";
    fill(visited.begin(), visited.end(), false); // 방문 배열 초기화
    BFS(Start);

    
}


void DFS(int node)
{
    cout << node << " "; // dfs 탐색 순서대로 id가 나옴
    visited[node] = true;

    for(int i: adj[node])
    {
        if(!visited[i]) // 만약 방문을 안했다면
        {
            DFS(i); //dfs 탐색!
        }
    }
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);

    visited[node] = true;

    while(!q.empty()) // 방문할 게 남아있다면(?)
    {
        int now = q.front();
        q.pop();

        cout << now << " "; //bfs 탐색 순서대로 id가 나옴

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