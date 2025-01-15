#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;
    int dot[N];

    //N개의 점 위치 구하기
    for(int i=0; i < N; i++)
    {
        cin >> dot[i];
    }

   
    sort(dot, dot + N);

    for(int i=0; i < M; i++)
    {
       
        bool flagS = false;
        bool flagE = false;
        int lineS, lineE, Sindex, Eindex;
        cin >> lineS >> lineE;

        if(lineS > dot[N-1] || lineE < dot[0]) //왜 &&이라고...참나
        {
            cout << 0 << "\n";
            continue; //break는 아예 반복문을 나감.
        }
        //이분 탐색
        // 이분 탐색의 기준은 항상 중간값 dot[midi]!! start<=end 조건 하에 dot[midi]와 동일한지 (==), 큰지 작은지 대소비교를 통해 1또는 -1을 언젠가 반환 ⭐⭐
        // 언제가 끝나는 기준점인 중간값을 이용하여 선분의 시작점 lineS가 중간값보다 클때...작을때.. lineE가 클때..작을때..생각하자
        else
        {
            int start = 0; //시작 점의 index: 0
            int end = N - 1; //마지막 점의 index: 4
            Sindex = N;  
            while (start <= end)
            {
                int midi = (start + end) /2;
                

                if(dot[midi] >= lineS)
                {
                    Sindex = midi;
                    end = midi - 1;
                }
                else
                {
                    start = midi + 1;
                }
            }

            
            
            start = 0; //시작 점의 index: 0 //다시 int로 선언할 필요없음
            end = N - 1; //마지막 점의 index: 4
            Eindex = 0;
            while(start <= end)
            {
                int midi = ( start + end )/ 2;
                

                if(dot[midi] <= lineE)
                {
                    Eindex = midi;
                    start = midi + 1;
                }
                else
                {
                    end = midi - 1;
                }
            }


            if(Eindex >= Sindex)
            {
                cout << Eindex - Sindex + 1 << "\n";
            }
            else
            {
                cout << 0 <<"\n"; //이걸 안적음
            }
            
                
        }
    }
    

    return 0;
}