#include <iostream>

using namespace std;

int main(){


    int N, M; // N: 수의 개수, M: 합을 구해야 하는 횟수
    
    cin >> N >> M;

    int arr[N+1];
    int S[N+1];
    int result[M];

    for(int i=0; i <= N; i++)
    {

        if(i==0)
        {
            arr[0] = 0;
            S[0] = 0;
            continue;
        }

        cin >> arr[i];

        if(i==1)
        {
            S[1] = arr[1];
            continue;
        }
        

        //합 배열 구하기
        S[i] = S[i-1] + arr[i];
    }


    // 구간 합 구하기
    for(int z=0; z < M; z++)
    {
        int i,j;

        cin >> i >> j;

        result[z] = S[j] - S[i-1]; // 원래는 S[j] - S[i-1]인데 문제에서 index 0번부터 처리안하고 1로 처리하여 -1씩 인덱스 빼줌.
    }

    // 출력
    for(int i=0; i < M; i++)
    {
        cout << result[i] << "\n";
    }

}
