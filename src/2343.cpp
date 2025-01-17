#include <iostream>
#include <algorithm>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M; // N: 강의 수, M: 블루레이 개수

    int arr[N];
    int totalArr = 0; // 하나의 블루레이에 최대로 닮을 수 있는 크기
    int start, end;

    for(int i=0; i < N; i++)
    {
        cin >> arr[i];
        totalArr += arr[i]; 
    }

    
    // 이진탐색할 거: 블루레이 크기가 될 수 있는 자연수 : 1 2 3 4 5 6 ..... 17 ... 999...
    start = *max_element(arr, arr+N); //⭐
    end = totalArr;
    int count = 1; //defalut가 전체 한묶음 //⭐
    int result = end; //⭐
    
    while(start <= end)
    {
        int midV = (start + end) / 2; //midV: 블루레이 크기가 될 수 있는 자연수
        int tempSum = 0;
        count = 1;

        for(int i = 0; i < N; i++)
        {
            if(tempSum + arr[i] > midV) //⭐
            {
                count ++;
                
                tempSum = 0;
            }

            tempSum += arr[i];
            
        }

        if(count <= M) //⭐
        {
            result = midV;
            end = midV -1;
        }
        else
        {
            start = midV + 1;
            
        }
        


    }

    cout<<result;

    return 0;
}
