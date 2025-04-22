/*
수식 함수 evaluate의 인자는 연산자 노드가 온다.
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
evaluate(BinaryNode* node) {  // 수식 트리 계산
	if (node == NULL) return 0;
	if (node->isLeaf()) return node->getData(); // 단말 노드이면, 피연산자
	else {  // 비단말 노드이면, 연산자
		int op1 = evaluate(node->getLeft());   // 왼쪽 서브트리 계산
		int op2 = evaluate(node->getRight()); // 오른쪽 서브트리 계산
		switch ((char)node->getData()) {	    // 수식 계산
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
	tree.resize(2 * N, NULL);  // 벡터 크기 확보

	// 1번부터 N번까지 노드 생성: 피연산자
	for (int i = 1; i <= N; i++)
	{
		cin >> val;
		tree[i] = new BinaryNode(val);
	}
	vector<int> left(2 * N);
	vector<int> right(2 * N);

	// N+1번부터 2*N-1번까지 노드 생성: 연산자
	for (int i = N + 1; i < 2 * N; i++) {
		cin >> type >> left[i] >> right[i];
		tree[i] = new BinaryNode(type);
	}

	// 트리 생성
	for (int i = N + 1; i < 2 * N; i++)
	{
		tree[i]->setLeft(tree[left[i]]);
		tree[i]->setRight(tree[right[i]]);
	}

	// 수식 계산 (2N-1: 루트 노드)
	cout << evaluate(tree[2 * N - 1]);
	return 0;
}