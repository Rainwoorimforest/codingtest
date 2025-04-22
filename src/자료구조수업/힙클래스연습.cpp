#include <iostream>

#define MAX_ELEMENT 200

using namespace std;

class HeapNode
{
	int key; //노드 key값

public:
	HeapNode (int k=0) : key(k) {}
	
	void setKey(int k) { key = k; } //노드에 키값 저장하기
	int getKey() { return key; } //노드에서 키값 받아오기
	void display() { cout << key << " "; } //노드 디스플레이

};

class MaxHeap
{
	HeapNode node[MAX_ELEMENT];
	int size;

public:
	MaxHeap() : size(0) { }// 처음엔 크기 0인 배열

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode getParent(int i) { return node[i / 2]; } //i의 부모노드 반환
	HeapNode getLeft(int i) { return node[1 * 2]; } //i의 왼쪽 자식노드 반환
	HeapNode getRight(int i) { return node[i * 2 + 1]; } //i의 오른쪽 자식 노드 반환

	void insert(int key);
	HeapNode remove();
	HeapNode find() { return node[1]; } //루트 노드 반환
};

int main()
{
	MaxHeap max;

	max.insert(1);
	max.insert(2);
	max.insert(3);
	max.insert(4);

	max.remove();

	return;

	

}