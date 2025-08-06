#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// vector<vector<int>> adj; //static이 뭐지?
vector<int> sortvector;
vector<vector<int>> height_map;
 // vector 크기, 형값 선언 까먹음
//이차원배열 어케하지. 이게 adj인가? 인접행렬..!!! ㅠㅠ

void BFS(vector<vector<bool>>& visited, int x, int y,int size)
{
    int count_inside=0; 
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty())
    {
        pair<int,int> now = q.front();
        q.pop();
        int now_x = now.first;
        int now_y = now.second;

        //상하좌우 이동
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
    
        for(int dir=0; dir<4; dir++)
        {
            int nx = now_x + dx[dir];
            int ny = now_y + dy[dir];

            if(nx>=1 && ny>=1 && nx < size && ny < size && !visited[nx][ny])
            {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }

            
        }
        

    }

}


int main(){
    int N;
    int count=0;
    int count_inside=0;
    int max=0;

    cin>>N;
    
    height_map.resize(N+1, vector<int>(N+1)); //모든 값은 0으로 초기화
    

 
    //입력
    for(int i=1; i<N+1; i++)
    {
        for(int j=1; j<N+1; j++)
        {
            int a;
            cin >> a;

            height_map[i][j] = a;
            sortvector.push_back(a);
        }
    }

    //최대 최소 구하기 로직 
    // 아니면 SORT하기..
    // int max_val = height_map[1][1];
    // int min_val = height_map[1][1];

    // for(auto &row: height_map)
    // {
    //     int row_max = *max_element(row.begin(), row.end());
    //     int row_min = *min_element(row.begin(), row.end());

    //     if(row_max > max_val) max_val = row_max;
    //     if(row_min < min_val) min_val = row_min;
    // }

    //sort + 중복제거
    sort(sortvector.begin(), sortvector.end());
    sortvector.erase(unique(sortvector.begin(),sortvector.end()), sortvector.end());
    
    //i 높이 이상은 visited에서 true로
    for(int h: sortvector)
    {
        int count_inside = 0;
        vector<vector<bool>> visited(N+1, vector<bool>(N+1,false));

        for(int i=1; i<height_map.size(); i++)
        {
            for(int j=1; j<height_map[i].size(); j++)
            {

                if(height_map[i][j] < h ) visited[i][j] = true;
                
            }
        }

        for(int i=1; i<height_map.size(); i++)
        {
            for(int j=1; j<height_map[i].size(); j++)
            {
                
                if(!visited[i][j]) //여기 논리오류 주의
                {
                    BFS(visited, i, j, N+1);
                    count_inside++;
                }
            }
        }

        if(count < count_inside)
        {
            count = count_inside; //max값 변경
        }

    }

    cout<< count<<endl; //최대값 출력


    return 0;
}
