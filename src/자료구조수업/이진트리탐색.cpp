#include <iostream>
#include <vector>

using namespace std;

class BinaryNode {
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val=0, BinaryNode* l=NULL, BinaryNode* r = NULL) : data(val),left(l),right(r){}
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
	~BinaryTree(){}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getData() { return root; }

	bool isEmpty() { return root == NULL; }

	void inorder() { inorder(root); }
	void preorder() { preorder(root); }
	void postorder() { postorder(root); }

private:

	void inorder(BinaryNode* node);
	void preorder(BinaryNode* node);
	void postorder(BinaryNode* node);


};

void BinaryTree::inorder(BinaryNode* node) //øﬁ- ∑Á∆Æ- ø¿
{
	if (node != NULL)
	{
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << "[" << node->getData() << "]";
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}

void BinaryTree::preorder(BinaryNode* node) //∑Á∆Æ-øﬁ-ø¿
{
	if (node != NULL)
	{
		cout << "[" << node->getData() << "]";
		if (node->getLeft() != NULL) preorder(node->getLeft());
		if (node->getRight() != NULL)preorder(node->getRight());
	}
}

void BinaryTree::postorder(BinaryNode* node) //øﬁ-ø¿-∑Á∆Æ
{
	if (node != NULL)
	{
		if (node->getLeft() != NULL) postorder(node->getLeft());
		if (node->getRight() != NULL) postorder(node->getRight());
		cout << "[" << node->getData() << "]";
	}
	
}

class BinSrchTree : public BinaryTree {

public:
	BinSrchTree(void){}
	~BinSrchTree(void) {}
	
	BinaryNode* search(int key);
	BinaryNode* search(BinaryNode* n, int key);

	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);


};

BinaryNode*  BinSrchTree::search(int key) {
	BinaryNode* node = search(root, key);
	if (node != NULL)
	{
		cout << "≈∞ ∞™: " << node->getData() << "¿Œ ≥ÎµÂ: " << node << endl;
	}
	else
	{
		cout << "≈ΩªˆΩ«∆–" << endl;
	}

	return node;
}

BinaryNode* BinSrchTree:: search(BinaryNode* n, int key) {
	if (n == NULL) return NULL;
	if (key == n->getData()) return n;
	else if (key < n->getData()) return search(n->getLeft(), key);
	else return search(n->getRight(), key);

}

void BinSrchTree::insert(BinaryNode* n)
{
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n)
{
	if (n->getData() == r->getData()) return;
	else if (n->getData() < r->getData()) {
		if (r->getLeft() == NULL) r->setLeft(n);
		else insert(r->getLeft(), n);

	}
	else {
		if (r->getRight() == NULL) r->setRight(n);
		else insert(r->getRight(), n);
	}
}

int main() {
	BinaryNode* node;
	BinSrchTree tree;
	//vector<BinaryNode*> nodes;

	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		BinaryNode* node = new BinaryNode(a);
		tree.insert(node);

		//if(i==0)
	}
	

	tree.postorder();

	return 0;
}