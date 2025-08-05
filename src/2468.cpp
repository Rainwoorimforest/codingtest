#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> adj; //static이 뭐지?
vector<vector<int>> height_map;
vector<bool> visited; // vector 크기, 형값 선언 까먹음
//이차원배열 어케하지. 이게 adj인가? 인접행렬..!!! ㅠㅠ


int main(){
    int N;
    height_map.resize(N+1, vector<int>(N+1)); //모든 값은 0으로 초기화


    //입력
    for(int i=1; i<N; i++)
    {
        for(int j=1; j<N; j++)
        {
            int a;
            cin >> a;

            height_map[i][j] = a;
        }
    }

    //최대 최소 구하기 로직 
    // 아니면 SORT하기..
    int max_val = height_map[1][1];
    int min_val = height_map[1][1];

    for(auto &row: height_map)
    {
        int row_max = *max_element(row.begin(), row.end());
        int row_min = *min_element(row.begin(), row.end());

        if(row_max > max_val) max_val = row_max;
        if(row_min < min_val) min_val = row_min;
    }

    //크기대로 BFS 반복
    cout<<"rne";




    return 0;
}
