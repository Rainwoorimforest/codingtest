#include <iostream>

#define MAX_ELEMENT 200

using namespace std;

class HeapNode
{
	int key; //��� key��

public:
	HeapNode (int k=0) : key(k) {}
	
	void setKey(int k) { key = k; } //��忡 Ű�� �����ϱ�
	int getKey() { return key; } //��忡�� Ű�� �޾ƿ���
	void display() { cout << key << " "; } //��� ���÷���

};

class MaxHeap
{
	HeapNode node[MAX_ELEMENT];
	int size;

public:
	MaxHeap() : size(0) { }// ó���� ũ�� 0�� �迭

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode getParent(int i) { return node[i / 2]; } //i�� �θ��� ��ȯ
	HeapNode getLeft(int i) { return node[1 * 2]; } //i�� ���� �ڽĳ�� ��ȯ
	HeapNode getRight(int i) { return node[i * 2 + 1]; } //i�� ������ �ڽ� ��� ��ȯ

	void insert(int key);
	HeapNode remove();
	HeapNode find() { return node[1]; } //��Ʈ ��� ��ȯ
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