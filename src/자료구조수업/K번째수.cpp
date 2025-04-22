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
    HeapNode node[MAX_ELEMENT];     // HeapNode Ŭ���� Ÿ�� �迭
    int size;                       // �� ��ҵ� ����
public:
    MaxHeap() : size(0) { }	    // ó���� ũ�� 0�� �迭
    bool isEmpty() { return size == 0; }		   // ��� �ִ���?
    bool isFull() { return size == MAX_ELEMENT - 1; }// ������ �ִ���

    HeapNode getParent(int i) { return node[i / 2]; }  // �θ� ���
    HeapNode getLeft(int i) { return node[i * 2]; }  // ���� �ڽ� ���
    HeapNode getRight(int i) { return node[i * 2 + 1]; } // ������ �ڽ� ���

    void insert(int key);      	// ���� �Լ�
    HeapNode remove();         	// ���� �Լ�
    HeapNode find() { return node[1]; }	// ��Ʈ ��� ��ȯ
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