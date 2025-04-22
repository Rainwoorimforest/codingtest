/*
���� �Լ� evaluate�� ���ڴ� ������ ��尡 �´�.
*/

#include <iostream>
#include <vector>

using namespace std;

class BinaryNode {

	int data;
	BinaryNode* left;
	BinaryNode* right;

public:

	BinaryNode(int val = 0, BinaryNode* l=NULL, BinaryNode* r=NULL): data(val), left(l), right(r) {}
	~BinaryNode() {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
};

int
evaluate(BinaryNode* node) {  // ���� Ʈ�� ���
	if (node == NULL) return 0;
	if (node->isLeaf()) return node->getData(); // �ܸ� ����̸�, �ǿ�����
	else {  // ��ܸ� ����̸�, ������
		int op1 = evaluate(node->getLeft());   // ���� ����Ʈ�� ���
		int op2 = evaluate(node->getRight()); // ������ ����Ʈ�� ���
		switch ((char)node->getData()) {	    // ���� ���
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		default: return 0;
		}
	}
}

int main()
{
	int N, val;
	char type;
	vector<BinaryNode*> tree;

	cin >> N;
	tree.resize(2 * N, NULL);  // ���� ũ�� Ȯ��

	// 1������ N������ ��� ����: �ǿ�����
	for (int i = 1; i <= N; i++)
	{
		cin >> val;
		tree[i] = new BinaryNode(val);
	}
	vector<int> left(2 * N);
	vector<int> right(2 * N);

	// N+1������ 2*N-1������ ��� ����: ������
	for (int i = N + 1; i < 2 * N; i++) {
		cin >> type >> left[i] >> right[i];
		tree[i] = new BinaryNode(type);
	}

	// Ʈ�� ����
	for (int i = N + 1; i < 2 * N; i++)
	{
		tree[i]->setLeft(tree[left[i]]);
		tree[i]->setRight(tree[right[i]]);
	}

	// ���� ��� (2N-1: ��Ʈ ���)
	cout << evaluate(tree[2 * N - 1]);
	return 0;
}