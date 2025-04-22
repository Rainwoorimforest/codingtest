#include <iostream>

using namespace std;

class BinaryNode {

	int data;
	BinaryNode* left;
	BinaryNode* right;

public: 
	BinaryNode(int val=0,BinaryNode* l=NULL,BinaryNode* r=NULL): data(val), left(l),right(r) {}
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
	BinaryTree(): root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }

	//�� �� �Լ�

	int getCount() { return isEmpty() ? 0 : getCount(root); }// ��� ����
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }	// �ܸ� ��� ����
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }	// Ʈ���� ����
	bool isFull() { return isEmpty() ? 0 : isFull(root); }	// full binary tree���� 
	int calcLevel(int n);  	// �����Ͱ� n�� ����� ����

	int getCount(BinaryNode* node);
	int getLeafCount(BinaryNode* node);
	int getHeight(BinaryNode* node);
	bool isFull(BinaryNode* node);
	int calcLevel(BinaryNode* node, int n, int level);

	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode* node);

	//��ȸ �Լ�
	void inorder() { inorder(root); }
	void preorder() { preorder(root); }
	void postorder() { postorder(root); }

	void inorder(BinaryNode* r);
	void preorder(BinaryNode* r);
	void postorder(BinaryNode* r);


	//����Ž��Ʈ�� Ȯ�� ���� �Լ�

	bool isBST(BinaryNode* r); //root�� ���� ������ �� ��Ʈ�� �������� ���� ����/������ ���� Ʈ���� BST���� Ȯ���߾�. ��� �� �ϸ�
	int minValue(BinaryNode* n); //���� ���� ���ڸ� �������� �ϴ� ���� ����Ʈ�� �� minimum�� ���� ���޹��� n�ڿ� �ּڰ���
	int maxValue(BinaryNode* n);

};



int BinaryTree::getCount(BinaryNode* node) { // � node�� ��Ʈ�� �ϴ� ����Ʈ���� ��� ������ ���ϴ� �Լ�
	if (node == NULL) return 0;
	return 1 + getCount(node->getLeft())
		+ getCount(node->getRight());
}

int BinaryTree::getLeafCount(BinaryNode* node) //������ ��� �Ϻο� �ִ� �ܸ� ����� ������ ���ϴ� �Լ�
{
	if (node == NULL) return 0;
	if (node->isLeaf()) return 1;
	else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
}

int BinaryTree::getHeight(BinaryNode* node)
{
	if (node == NULL) return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return (hLeft > hRight) ? 1 + hLeft : 1 + hRight;
}

int BinaryTree::evaluate(BinaryNode* node)
{  // ���� Ʈ�� ���
	if (node == NULL) return 0;
	if (node->isLeaf()) return node->getData();
	else {  // ��ܸ� ����̸�
		int op1 = evaluate(node->getLeft());
		int op2 = evaluate(node->getRight());
		switch (node->getData()) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
		return 0;
	}
}
/* Ʋ���ڵ�

bool BinaryTree::isFull(BinaryNode* node)
{
	if (node == NULL) return true;
	if (node->left == NULL && node->right == NULL) return true;
	if (node->left != NULL && node->right != NULL)
		return isFull(node->left) and isFull(node->right);
	else return false;
}


int BinaryTree::calcLevel(int n)
{
	return isEmpty() ? 0 : calcLevel(root, n, 1);
}

int
BinaryTree::calcLevel(BinaryNode* node, int n, int level)
{
	if (node == NULL) return 0;
	if (node->data == n) return level;
	int ll = calcLevel(node->left, n, level + 1);
	if (ll != 0) return ll;
	ll = calcLevel(node->right, n, level + 1);
	return ll;
}
*/

void BinaryTree::inorder(BinaryNode* r) //�� - ��Ʈ - ��
{
	if (r != NULL)
	{
		if (r->getLeft() != NULL) inorder(r->getLeft());
		cout << "[" << r->getData() << "]";
		if (r->getRight() != NULL) inorder(r->getRight());
	}
}

void BinaryTree::preorder(BinaryNode* r) //��Ʈ -�� - ��
{
	if (r != NULL)
	{
		cout << "[" << r->getData() << "]";
		if (r->getLeft() != NULL) preorder(r->getLeft());
		if (r->getRight() != NULL) preorder(r->getRight());
	}
}

void BinaryTree::postorder(BinaryNode* r) //��-��-��Ʈ
{
	if (r != NULL)
	{
		if (r->getLeft() != NULL) postorder(r->getLeft());
		if (r->getRight() != NULL) postorder(r->getRight());
		cout << "[" << r->getData() << "]";
	}
}


//����Ž��Ʈ�� Ȯ�� ���� �Լ�

int BinaryTree::minValue(BinaryNode* node)
{
	if (node == NULL) return INT16_MAX;

	int value = node->getData();
	int leftMin = minValue(node->getLeft());
	int rightMin = minValue(node->getRight());

	return min(value, min(leftMin, rightMin));
}

int BinaryTree::maxValue(BinaryNode* node)
{
	if (node == NULL) return INT16_MIN;

	int value = node->getData();
	int leftMax = maxValue(node->getLeft());
	int rightMax = maxValue(node->getRight());

	return max(value, max(leftMax, rightMax));
}

//���� �Լ� �� Ʋ��.  if 4��
bool BinaryTree::isBST(BinaryNode* node)
{
	if (node == NULL) return true;
	if (node->getLeft() != NULL
		&& maxValue(node->getLeft()) >= node->getData()) return false;
	if (node->getRight() != NULL
		&& minValue(node->getRight()) <= node->getData()) return false;
	if (!isBST(node->getLeft()) || !isBST(node->getRight())) return false;
	return true;
}

class BinSrchTree : public BinaryTree
{
	int key;

public:
	BinSrchTree(void){}
	~BinSrchTree(void) {}

	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);

	BinaryNode* search(int key);
	BinaryNode* search(BinaryNode* n, int key);
	
	void remove(int key);
	void remove(BinaryNode* parent, BinaryNode* node);
};

void BinSrchTree::insert(BinaryNode* n)
{
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n)
{
	if (r->getData() == n->getData()) return;
	else if (r->getData() > n->getData())
	{
		if (r->getLeft() == NULL) r->setLeft(n);
		else insert(r->getLeft(), n);
	}
	else
	{
		if (r->getRight() == NULL) r->setRight(n);
		else insert(r->getRight(), n);
	}
}

BinaryNode* BinSrchTree::search(int key)
{
	BinaryNode* node = search(root, key);

	if (node != NULL)
	{
		cout << "Ž������ Ű ����: " << node->getData() << "�� �ּҴ� " << node;

	}
	else
	{
		cout << "Ž������" << endl;
		return;
	}

	return node;
}

BinaryNode* BinSrchTree::search(BinaryNode* n, int key)
{
	if (n == NULL) return NULL;

	if (key == n->getData()) return n;
	else if (key < n->getData()) return search(n->getLeft(), key);
	else return search(n->getRight(), key);
}

void BinSrchTree::remove(int key)
{
	if (isEmpty()) return; //�� Ʋ��

	BinaryNode *parent = NULL;
	BinaryNode *node = root;

	while (node != NULL && key != node->getData())
	{
		parent = node;
		node = (key < node->getData()) ? node->getLeft() : node->getRight();
	}

	if (node == NULL)
	{
		cout << "error"; return;
	}
	else remove(parent, node);
}

void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node)
{
	//case1
	if (node->isLeaf())
	{
		if (parent == NULL) root = NULL;
		else
		{
			if (parent->getLeft() == node) parent->setLeft(NULL);
			else parent->setRight(NULL);
		}
	}

	//case2
	else if (node->getLeft()==NULL || node->getRight()==NULL)
	{
		BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

		if (node == root) root = child;

		if (parent->getLeft() == node)
		{
			parent->setLeft(child);
		}
		else
		{
			parent->setRight(child);
		}
	}
	
	//case3
	else
	{
		int leftmost, rightmost;

		BinaryNode* succp = node;
		BinaryNode* succ = node->getRight();

		BinaryNode* succp2 = node;
		BinaryNode* succ2 = node->getLeft();

		while (succ->getLeft() != NULL)
		{
			succp = succ;
			succ = succ->getLeft();
		}

		while (succ2->getRight() != NULL)
		{
			succp2 = succ2;
			succ2 = succ->getRight();
		}

		leftmost = succ->getData() - node->getData();
		rightmost = node->getData() - succ2->getData();

		if (leftmost < rightmost) // leftmost���� ���̰� �� ����. -> leftmost�� ��ü
		{
			if (succp->getLeft() == succ) succp->setLeft(succ->getRight());
			else succp->setRight(succ->getRight());

			node->setData(succ->getData());
			node = succ;
		}
		else //leftmost > rightmost
		{
			if (succp2->getRight() == succ2) succp2->setRight(succ->getLeft());
			else succp2->setLeft(succ->getLeft());

			node->setData(succ2->getData());
			node = succ2;
		}
		/*
		if (succp->getLeft() == succ) succp->setLeft(succ->getRight());
		else succp->setRight(succ->getRight());

		node->setData(succ->getData());
		node = succ;
		*/
	}

	delete node;
}



