#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N; 
    cin >> N;

    int arr[100]; 
    int result[100]; //��� �迭

    stack<int> s;

    for (int i = 0; i < N; i++) { //���� �迭 ä���
        int x;

        cin >> x;
        arr[i] = x;
    }
    s.push(0); //���� ���� �ʱ�ȭ

    for (int i = 0; i < N; i++) 
    {
        while (!s.empty() && arr[i] > arr[s.top()]) 
        {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int x = s.top();
        result[x] = -1;
        s.pop();
    }
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    return 0;
}