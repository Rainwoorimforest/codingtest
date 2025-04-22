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


	bool isBST(BinaryNode* node); //����Ʈ��Ȯ���ϴ� �Լ�
	int minValue(BinaryNode* node); // ���ڷ� ���� node�� ��Ʈ�� ����. �� ����Ʈ���� �ּڰ� ã�� �Լ� 
	int maxValue(BinaryNode* node); //���ڷ� ���� ��带 ��Ʈ�� �ϴ� ����Ʈ���� �ִ��� ã�� �Լ�


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
	if (node == NULL) return INT16_MIN; //INT16_MAX �ƴ�

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

	//���� ����� ���� �Ǵ� ������ ����Ʈ�� �� �ϳ��� BST�� �ƴ϶�� false�� ��ȯ.
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
		if (r->getLeft() == NULL) r->setLeft(n); //r�� ���ʿ� ���ؼ� ���ǵ� r�� ������ �ִ������� �˻�.
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

	//�Է¹ޱ�
	for (int i = 1; i <= N; i++)
	{
		node[i] = new BinaryNode(i);
	}

	//��� �� ��ũ ����
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



	//����Ž��Ʈ�� ���� Ȯ�� ���̵��
	// Root�� leftmost,rightmost�� ���Ͽ� ���ϱ�


	if (tree.isBST(tree.getRoot())) cout << "\n1";
	else cout << "\n0";

	return 0;


}