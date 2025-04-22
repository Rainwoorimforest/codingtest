#include <iostream>
#include <vector>
#include <string>



using namespace std;

class BinaryNode {

	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val=0, BinaryNode* l=NULL, BinaryNode* r=NULL) : data(val), left(l), right(r) {}
	~BinaryNode() {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
};

class BinaryTree {

protected:
	BinaryNode* root;

public:
	BinaryTree() : root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }


	bool isBST(BinaryNode* node); //이진트리확인하는 함수
	int minValue(BinaryNode* node); // 인자로 받은 node를 루트로 가져. 그 서브트리의 최솟값 찾는 함수 
	int maxValue(BinaryNode* node); //인자로 받은 노드를 루트로 하는 서브트리의 최댓값을 찾는 함수


};


int BinaryTree::minValue(BinaryNode* node)
{
	if (node == NULL) return INT16_MAX;

	int value = node->getData();
	int leftmin = minValue(node->getLeft());
	int rightmin = minValue(node->getRight());

	return min(value, min(leftmin, rightmin));
}

int BinaryTree :: maxValue(BinaryNode* node)
{
	if (node == NULL) return INT16_MIN; //INT16_MAX 아님

	int value = node->getData();
	int leftmax = maxValue(node->getLeft());
	int rightmax = maxValue(node->getRight());

	return max(value, max(leftmax, rightmax));
}

bool BinaryTree::isBST(BinaryNode* node)
{
	if (node == NULL) return true;

	if (node->getLeft() != NULL && maxValue(node->getLeft()) >= node->getData()) return false;
	if (node->getRight() != NULL && minValue(node->getRight()) <= node->getData()) return false;

	//현재 노드의 왼쪽 또는 오른쪽 서브트리 중 하나라도 BST가 아니라면 false를 반환.
	if(!isBST(node->getLeft()) || !isBST(node->getRight())) return false;

	return true;
}


class BinSrchTree : public BinaryTree {

public:
	BinSrchTree(void){}
	~BinSrchTree(void) {}
	
	//BinaryNode* search(int key);
	//BinaryNode* search(BinaryNode* n,int key);


	void insert(BinaryNode* n);
	BinaryNode* insert(BinaryNode* r,BinaryNode* n);

};

void BinSrchTree::insert(BinaryNode* n) 
{
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}

BinaryNode* BinSrchTree::insert(BinaryNode* r, BinaryNode* n)
{
	if (r->getData() == n->getData()) return NULL;
	else if (r->getData() > n->getData())
	{
		if (r->getLeft() == NULL) r->setLeft(n); //r의 왼쪽에 대해서 갈건데 r에 왼쪽이 있는지부터 검사.
		else insert(r->getLeft(), n);
	}
	else
	{
		if (r->getRight() == NULL) r->setRight(n);
		else insert(r->getRight(), n);

	}
}



 

int main() {

	int N;

	BinSrchTree tree;
	vector<BinaryNode*> node;
	cin >> N;

	node.resize(N+1);

	//입력받기
	for (int i = 1; i <= N; i++)
	{
		node[i] = new BinaryNode(i);
	}

	//노드 간 링크 연결
	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;

		if (left != '.') node[root - '0']->setLeft(node[left - '0']);
		else node[root - '0']->setLeft(NULL);
		if (right != '.') node[root - '0']->setRight(node[right - '0']);
		else node[root - '0']->setRight(NULL);

		if (i == 0)
		{
			tree.setRoot(node[root - '0']);
		}
	}



	//이진탐색트리 여부 확인 아이디어
	// Root와 leftmost,rightmost를 구하여 비교하기


	if (tree.isBST(tree.getRoot())) cout << "\n1";
	else cout << "\n0";

	return 0;


}