/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // fixed와 setprecision 사용을 위해 추가

using namespace std;

int main() {
    int N; 
    cin >> N;

    vector<int> scores(N); // N 크기로 벡터 초기화

    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    // 최대값 찾기
    int maxScore = *max_element(scores.begin(), scores.end());

    // 점수 변환 및 합계 계산
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += static_cast<double>(scores[i]) / maxScore * 100.0;
    }

    // 평균 출력
    cout << fixed << setprecision(6) << (sum / N) << endl;

    return 0;
}
 */