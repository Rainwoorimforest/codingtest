#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, N, M; //T 테스트 케이스는 왜 있는거지?
    
    cin >> T >> N;

    vector<int> A(N); //수첩1, 비교 당하는 근본 데이터
    vector<int> result;

    //수첩1 입력 받기
    for(int i=0; i < N; i++)
    {
        cin >> A[i];
    }

    //STEP 1: 수첩1, 근본 데이터 정렬하기
    sort(A.begin(), A.end());
    
    cin >> M;
    
    for(int i=0; i < M; i++)
    {
        int target;
        bool find = false;

        cin >>target;

        // 이진 탐색 시작
        int start = 0;
        int end = A.size() -1;
        
        while(start <= end)
        {
            int midi = (start + end) /2;
            int midV = A[midi];

            if(midV > target) // 왼쪽 데이터셋만 남기기
            {
                end = midi - 1;
            }    
            else if(midV < target) // 오른쪽 데이터셋만 남기기
            {
                start = midi + 1;
                
            }
            else
            {
                find = true;
                
            }

            
        }


        if(find)
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }
    
    }

    //출력
    for(int i=0; i< result.size(); i++)
    {
        cout << result[i] << "\n";
    }

    return 0;

}