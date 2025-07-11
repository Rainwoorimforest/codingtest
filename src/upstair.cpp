#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> D;
vector<int> J; //i만큼 점프했을때 누적..

int main() {
    // int sum = 0;

    cin >> N;
    D.resize(N + 1); //0=시작
    J.resize(N + 1);

    //점수 초기화
    for (int i = 0; i <= N; i++)
    {
        if (i == 0) { //dp 초기화 0번쨰쨰
            D[i] = 0;
            continue;
        }

        cin >> D[i];

    }

    for (int i = 0; i <= N; i++)
    {
        J[i] = 0;
    }

    // dp 초초기화
    // sum = sum + D[i];
    J[0] = D[0]; //0
    J[1] = D[1]; //10

    // J[N] = max(J[N-1]+D[N], J[N-2]+D[i]); // top-down임..

    for (int i = 2; i <= N; i++) //이렇게 하면 bottom-up이 되나?
    {
        J[i] = max(J[i - 3] + D[i - 1] + D[i], J[i - 2] + D[i]);

    }

    cout << J[N];


}


