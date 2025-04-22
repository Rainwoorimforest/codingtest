#include <iostream>

using namespace std;

class HeapNode {
	int key;
public:
	HeapNode(int k=0): key(k){}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { cout << key << ""; }
};

#define MAX_ELEMENT 200

class MaxHeap
{
    HeapNode node[MAX_ELEMENT];     // HeapNode 클래스 타입 배열
    int size;                       // 힙 요소들 개수
public:
    MaxHeap() : size(0) { }	    // 처음엔 크기 0인 배열
    bool isEmpty() { return size == 0; }		   // 비어 있는지?
    bool isFull() { return size == MAX_ELEMENT - 1; }// 가득차 있는지

    HeapNode getParent(int i) { return node[i / 2]; }  // 부모 노드
    HeapNode getLeft(int i) { return node[i * 2]; }  // 왼쪽 자식 노드
    HeapNode getRight(int i) { return node[i * 2 + 1]; } // 오른쪽 자식 노드

    void insert(int key);      	// 삽입 함수
    HeapNode remove();         	// 삭제 함수
    HeapNode find() { return node[1]; }	// 루트 노드 반환
};

void main()
{
    HeapNode node;
    MaxHeap heap;
    int n, k, num;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        heap.insert(num);
    }

    for (int i = 0; i < k; i++)
        node = heap.remove();
    cout << endl << node.getKey() << endl;
}