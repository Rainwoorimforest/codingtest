// 동적 계획법
// 피보나치 수열 - top down 방식
//큰 문제를 작은 문제로 나누고, 중복된 계산 결과를 저장해서 효율적으로 푸는 알고리즘 기법
// ➡️ 핵심은 중복되는 부분 문제 + 메모이제이션(저장)
#include <iostream>
#include <vector>

using namespaced std;

int N;
vector<int> D;

int main(){
    cin >> N;
    D.resize(N); // 많은 문제에서는 인덱스가 1부터 시작하는 입력을 주기 때문

    // -1로 flag하여 D vector 초기화
    for(int i = 0; i<=N; i++)
    {
        D[i] = -1;
    }

    //초기값은 대입
    D[0] = 0;
    D[1] = 1;
    fibo(5);


}

int fibo(int n){

    if (D[n] != -1) //초기값 넣기
    {
        return D[n]; // 0, 1,
    }

    return D[n] = fibo(n-1) + fibo(n-2);
}