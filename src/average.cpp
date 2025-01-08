#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; 
    float sum=0;
    vector<double> scores;

    cin >> N;

    for(int i=0; i < N; i++){ // 벡터는 동적 크기라 크기를 지정해주지 않으면 cin >> scores[i] 불가. 배열은 가능

        int a;
        cin >> a;
        scores.push_back(a); 
    }


    vector<double>::iterator M = max_element(scores.begin(), scores.end());

    for(int i=0; i< N; i++){

        double a= scores[i];
        scores[i] = a / *M * 100.0; 
        sum += scores[i];
    }

    cout << sum / N ;

    
}