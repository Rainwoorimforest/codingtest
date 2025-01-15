#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    bool find = false;
    cin >> K >> N;

    int arr[K];

    // 길이가 401일 때, 각각의 K개의 랜선에서 401cm로 만들 수 있는 개수 count를 구한다.
    // 이 count가 N개인지, N개보다 큰지, N개보다 작은지 Yes or No 탐색하는 것이 파라매트릭 알고리즘!

    for(int i=0; i < K; i++)
    {
        cin >> arr[i];
    }

    long long max_len = *max_element(arr, arr + K); // 배열의 포인터를 반환하므로 인자로 arr, *을 이용하여 value값 반환

    long long start = 1;
    long long end = max_len;
    long long count = 0;
    long long midV;


    while(start <= end)
    {
        midV = (start + end) / 2; // midV : 401

        for(int i=0; i < K; i++)
        {
           count += arr[i] / midV;
        }

        if( count >= N )
        {
            start = midV + 1;
            find = true;
            
        }
        else // 길이를 줄여
        {
            end = midV - 1;
        }

        count = 0;

    }

    if(find)
    {
        cout << end; // 출력은 midV가 아니라 end임!
    }
    
    return 0;

}