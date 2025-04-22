#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>

using namespace std;

int main() {

    int N,num;
    string command;

    stack<int> stack;

    cin >> command >> num;

    if (command == "push") {
        stack.push(num);
    }

    if (command == "pop") {
        stack.pop();
    }

    if (command == "siz") {
        stack.size();
    }

    if (command == "empty") {
        stack.empty();
    }




    
}


























/*
class Stack {
   
    int* arr;
    

public:
    Stack(int size = N); //생성자
    ~Stack();  //소멸자

    void push(int);
    int pop();
    

   
    if (command == "push") {


    }





};


int main() {

    int N;

    Stack pt(N);

    
    int N; //배열의 크기를 입력 받을 변수
    int* p;
    string command;

    cin >> N; //배열의 크기를 입력 받음
    
    Stack st1;
    cin >> command >> 

   // p = new int[N]; //입력받은 크기만큼 배열을 동정 생성
   

   
    

    return 0;
}

*/