#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;
    int arr[N];

    for(int i=0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int start = 0;
    int end = N - 1;
    int j = 0;

    while (start <= end)
    {
        int midi = (start + end) / 2;
        vector<int> SumV;
        int min, minBefore, pivotIndex;

        
        for(int i=0; i < N-1; i++)
        {
            int pivot = arr[j];

            SumV.push_back(pivot + arr[i+1]);
        }

        auto it = find(SumV.begin(), SumV.end(), 0);
        min = *min_element(SumV.begin(), SumV.end());
        
        if(it != SumV.end()) //0이 없다면
        {
            if()

            //SumV.clear
        }
        else
        {
            int index = distance(SumV.begin(), it); //인덱스 반환
            cout << arr[j] <<" "<<arr[index+j+1] <<"\n";
        }


        // 합 중에 0이 있어? - yes: 최적! no: ㄱㅊ 더 찾아봐
        //// 절댓값이 가장 작은 값.
        j++;
    }
    
}