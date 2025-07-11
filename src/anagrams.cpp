#include <iostream>
#include <sstream> // istringstream 쓸려면 임포
#include <string>
#include <algorithm>

using namespace std;

int N;
int main() {

    cin >> N;
    cin.ignore(); // 위의 코드때문에 개행 문자 '/n'을 꼭 제거해줘야해

    // 입력
    for (int i = 0; i < N; i++)
    {
        string s;
        getline(cin, s); //공백 포함 받음

        istringstream iss(s); //공백 기준의 문장을 구문 단위로 분리해줌줌

        string A, B;

        iss >> A >> B; //공백 기준 A,B에 단어를 각각 대입

        string sortedA = A;
        string sortedB = B;

        sort(A.begin(), A.end()); //sort 함수는 반환값이 없음!!?
        sort(B.begin(), B.end());

        if (A == B) cout << sortedA << '&' << sortedB << "are anagrams." << endl;
        else cout << sortedA << '&' << sortedB << "are NOT anagrams." << endl;



    }

    return 0;


}