#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> D;

int main() {
    cin >> N;
    D.resize(N);


    //�ʱ�ȭ
    for (int i = 0; i <= N; i++)
    {
        D[i] = -1;
    }

    D[0] = 0;
    D[1] = 1;

    //�Ǻ���ġ ���� (���� ��)
    for (int i = 2; i <= N + 2; i++)
    {
        D[i] = D[i - 1] + D[i - 2];
    }

    return D[N];
}