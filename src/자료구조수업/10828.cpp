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
    Stack(int size = N); //������
    ~Stack();  //�Ҹ���

    void push(int);
    int pop();
    

   
    if (command == "push") {


    }





};


int main() {

    int N;

    Stack pt(N);

    
    int N; //�迭�� ũ�⸦ �Է� ���� ����
    int* p;
    string command;

    cin >> N; //�迭�� ũ�⸦ �Է� ����
    
    Stack st1;
    cin >> command >> 

   // p = new int[N]; //�Է¹��� ũ�⸸ŭ �迭�� ���� ����
   

   
    

    return 0;
}

*/