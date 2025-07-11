#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> D;
vector<int> J; //i��ŭ ���������� ����..

int main() {
    // int sum = 0;

    cin >> N;
    D.resize(N + 1); //0=����
    J.resize(N + 1);

    //���� �ʱ�ȭ
    for (int i = 0; i <= N; i++)
    {
        if (i == 0) { //dp �ʱ�ȭ 0������
            D[i] = 0;
            continue;
        }

        cin >> D[i];

    }

    for (int i = 0; i <= N; i++)
    {
        J[i] = 0;
    }

    // dp ���ʱ�ȭ
    // sum = sum + D[i];
    J[0] = D[0]; //0
    J[1] = D[1]; //10

    // J[N] = max(J[N-1]+D[N], J[N-2]+D[i]); // top-down��..

    for (int i = 2; i <= N; i++) //�̷��� �ϸ� bottom-up�� �ǳ�?
    {
        J[i] = max(J[i - 3] + D[i - 1] + D[i], J[i - 2] + D[i]);

    }

    cout << J[N];


}


