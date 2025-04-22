#include <iostream>
#include <vector>


using namespace std;

class BinaryNode {

	int data;
	BinaryNode* left;
	BinaryNode* right;

public:

	BinaryNode(int val=0, BinaryNode* l=NULL, BinaryNode* r=NULL): data(val),left(l), right(r) {}
	~BinaryNode(){}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	//bool isLeaf
};

class BinaryTree {

protected:
	BinaryNode* root;

public:
	BinaryTree(void): root(NULL) {}
	~BinaryTree(void) {}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	//이진탐색트리여부

	bool isBST(BinaryNode* n);
	int minValue(BinaryNode* n);
	int maxValue(BinaryNode* n);

};

int BinaryTree::minValue(BinaryNode* n)
{
	if (n->getData()== NULL) return INT16_MAX;

	int value = n->getData();
	int Leftmin = minValue(n->getLeft()); //n의 자식 노드 중 왼쪽 노드부터 minValue인거 검사.
	int Rightmin = minValue(n->getRight());

	return min(value, min(Leftmin, Rightmin));
}

int BinaryTree::maxValue(BinaryNode* n)
{
	if (n == NULL) return INT16_MIN;

	int value = n->getData();
	int Leftmax = maxValue(n->getLeft());
	int Rightmax = maxValue(n->getRight());

	return max(value, max(Leftmax, Rightmax));
}

bool BinaryTree::isBST(BinaryNode* n)
{
	if (n == NULL) return true; // 아무것도 없을 떄도 이진트리임.

	if (n->getLeft() != NULL && maxValue(n->getLeft()) >= n->getData()) return false;
	if (n->getRight() != NULL && minValue(n->getRight()) <= n->getData()) return false;

	if (!isBST(n->getRight()) || !isBST(n->getLeft()))  return false;

	return true;
}


int main() {
	int N;
	BinaryTree tree;
	vector<BinaryNode*> v;

	cin >> N;

	v.resize(N + 1);

	//노드 생성
	for (int i = 1; i <= N; i++)
	{
		v[i] = new BinaryNode(i);
	}

	//노드 간 링크 연결 및 입력받기
	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;

		if (left != '.') v[root - '0']->setLeft(v[left - '0']);
		else v[root - '0']->setLeft(NULL);
		if (right != '.') v[root - '0']->setRight(v[right - '0']);
		else v[root - '0']->setRight(NULL);

		if (i == 0) tree.setRoot(v[root - '0']);

	}

	//검사
	if (tree.isBST(tree.getRoot())) cout << "1\n";
	else cout << "0\n";

	return 0;


}