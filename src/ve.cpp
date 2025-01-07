// vector 사용법
#include<iostream>
#include<vector>

using namespace std;

int main(){

    //선언
    vector<int> A;

    // 삽입 연산
    A.push_back(1); //마지막에 1추가
    A.insert(A.begin(), 7); //맨 앞에 7을 삽입
    A.insert(A.begin()+2, 10); //index 2에 위치에 10삽입

    // 7 1 10

    // 값 변경
    A[4] = -5;

    //삭제 연산
    A.pop_back(); // 마지막 값 삭제
    A.erase(A.begin()+3); //index 3에 해당하는 값 삭제
    A.clear(); // 모든 값 삭제

    // 정보 가져오기
    cout << A.front()<<endl; 
    cout << A.back()<<endl; //마지막 값
    cout << A.at(5)<<endl;
    cout << A[5] << endl;
    // cout << A.begin()<<endl;
    // cout << A.end()<<endl; //마지막 데이터 다음 위치
    

    for(int i=0; i < A.size(); i++)
    {
        cout<< A[i] <<" ";
    }


    return 0;
    
}