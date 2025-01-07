#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, number;
    int sum=0;

    cin >> N;
    cin >> number;

    vector<int> arr(N);

    
    for(int i =0; i < N; i++)
    {
        int a;
        cin >> arr[i];
    }


    for(int i=0; i < N; i++)
    {
        sum += arr[i];
    }

    cout << sum;

    return 0;
}