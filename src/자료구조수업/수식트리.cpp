#include <iostream>
#include <vector>

using namespace std;

class BinaryNode
{
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val=0, BinaryNode* l=NULL, BinaryNode* r =NULL) : data(val), left(l), right(r){}
	~BinaryNode(){}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* I) { left = I; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeft() { return left == NULL && right == NULL; }

};

class BinaryTree
{
	BinaryNode* root;

public: 
	
	BinaryTree():root(NULL) {}
	~BinaryTree(){}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	void inorder() { cout << endl<< "inorder: "; inorder(root); }
	void preorder() { cout << endl << "preorder: "; preorder(root); }
	void postorder() { cout << endl << "postorder: "; postorder(root); }


private:

	void inorder(BinaryNode* node);
	void preorder(BinaryNode* node);
	void postorder(BinaryNode* node);
};

void BinaryTree::inorder(BinaryNode* node)
{
	if(node != NULL)
	{
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << "[" << (char)(node->getData()) << "]";
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}

void BinaryTree::preorder(BinaryNode* node)
{
	if (node != NULL)
	{
		cout << "[" << (char)(node->getData()) << "]";
		if (node->getLeft() != NULL) preorder(node->getLeft());
		if (node->getRight() != NULL) preorder(node->getRight());
	}
}

void BinaryTree::postorder(BinaryNode* node)
{
	if (node != NULL)
	{
		if (node->getLeft() != NULL) postorder(node->getLeft());
		if (node->getRight() != NULL) postorder(node->getRight());
		cout << "[" << (char)(node->getData()) << "]";
	}
}

int main() {
	int N;
	char root, left, right;
	vector<BinaryNode*> node;
	BinaryTree tree= BinaryTree();

	cin >> N;


	//노드 이름 할당
	for (int i = 0; i < N; i++)
	{
		node.push_back(new BinaryNode('A'+i)); //벡터에는 숫자가 들어감.
	}

	//노드 간 링크 연결
	for (int i = 0; i < N; i++)
	{
		cin >> root >> left >> right;
		if (left != '.') { node[root - 'A']->setLeft(node[left - 'A']); } //문자 - 'A'
		if (right != '.') { node[root - 'A']->setRight(node[right - 'A']); }

	}

	tree.setRoot(node[0]);

	//까먹지말 것
	//BinaryNode* root = tree.getRoot();

	//순회
	tree.preorder();
	tree.inorder();
	tree.postorder();


	/*
	tree.preorder(tree.getRoot());
	tree.inorder(tree.getRoot());
	tree.postorder(tree.getRoot());
	*/
	return 0;

}