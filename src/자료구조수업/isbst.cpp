#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*


BinaryNode 노드 클래스


*/
class BinaryNode
{
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) : data(val), left(l), right(r) { }
	~BinaryNode() {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isEmpty() { return this == NULL; } //this?
	bool isLeaf() { return left == NULL && right == NULL; }


};


/*


BinaryTree 이진트리 클래스


*/
class BinaryTree {

protected:
	BinaryNode* root;


public:


	BinaryTree() : root(NULL) { }
	~BinaryTree() { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	// Tree Operation
	int getCount();		// 노드 개수
	int getLeafCount();	// 단말 노드 개수
	int getHeight();	// 트리의 높이
	bool isFull();		// full binary tree인지 
	int calcLevel(int n);  	// 데이터가 n인 노드의 레벨

	int getCount(BinaryNode* node);
	int getLeafCount(BinaryNode* node);
	int getHeight(BinaryNode* node);
	bool isFull(BinaryNode* node);
	int calcLevel(BinaryNode* node, int n, int level);


	void inorder() { cout << endl << "inorder: ";       inorder(root); }
	void preorder() { cout << endl << "preorder: ";    preorder(root); }
	void postorder() { cout << endl << "postorder: ";   postorder(root); }
	void levelorder();
	int evaluate();

	void inorder(BinaryNode* node);
	void preorder(BinaryNode* node);
	void postorder(BinaryNode* node);
	int evaluate(BinaryNode* node);

	//BinaryNode* insert(int n);
	//BinaryNode* insert(BinaryNode* r, int n);

	int minValue(BinaryNode* node);
	int maxValue(BinaryNode* node);

	bool isBST(BinaryNode* node);
};



int BinaryTree::getCount()
{
	return isEmpty() ? 0 : getCount(root);
}
int BinaryTree::getCount(BinaryNode* node)
{
	if (node == NULL) return 0;
	return 1 + getCount(node->getLeft())
		+ getCount(node->getRight());
}


int BinaryTree::getLeafCount()
{
	return isEmpty() ? 0 : getLeafCount(root);
}


int BinaryTree::getLeafCount(BinaryNode* node)
{
	if (node == NULL) return 0;
	if (node->isLeaf()) return 1;
	else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());


}


int BinaryTree::getHeight()
{
	return isEmpty() ? 0 : getHeight(root);
}


int BinaryTree::getHeight(BinaryNode* node)
{
	if (node == NULL) return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return (hLeft < hRight) ? hLeft + 1 : hRight + 1;
}

bool BinaryTree::isFull()
{
	return isEmpty() ? true : isFull(root);
}

bool BinaryTree::isFull(BinaryNode* node)
{
	if (node == NULL) return true; // 빈 트리는 완전 이진 트리로 간주합니다.

	// 노드가 단말 노드가 아니면서 자식 노드 중 하나가 없으면 완전 이진 트리가 아닙니다.
	if ((node->getLeft() && !node->getRight()) || (!node->getLeft() && node->getRight()))
		return false;

	// 재귀적으로 자식 노드를 확인합니다.
	return isFull(node->getLeft()) && isFull(node->getRight());
}

int BinaryTree::calcLevel(int n)
{
	if (isEmpty()) return -1; // 트리가 비어있으면 데이터를 찾을 수 없으므로 -1을 반환합니다.
	return calcLevel(root, n, 0);
}

int BinaryTree::calcLevel(BinaryNode* node, int n, int level)
{
	if (node == NULL) return -1; // 데이터를 찾지 못한 경우 -1을 반환합니다.

	if (node->getData() == n) return level; // 데이터를 찾은 경우 현재 레벨을 반환합니다.

	// 왼쪽 서브트리와 오른쪽 서브트리에서 데이터를 찾습니다.
	int leftLevel = calcLevel(node->getLeft(), n, level + 1);
	int rightLevel = calcLevel(node->getRight(), n, level + 1);

	// 데이터가 한 쪽 서브트리에만 있을 경우 해당 레벨을 반환합니다.
	if (leftLevel != -1) return leftLevel;
	if (rightLevel != -1) return rightLevel;

	// 데이터가 어느 쪽 서브트리에도 없으면 -1을 반환합니다.
	return -1;
}

void BinaryTree::inorder(BinaryNode* node)
{
	if (node != NULL) {
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << (char)(node->getData());
		if (node->getRight() != NULL) inorder(node->getRight());
	}

}

void BinaryTree::preorder(BinaryNode* node)
{
	if (node != NULL) {
		cout << (char)(node->getData());
		if (node->getLeft() != NULL) preorder(node->getLeft());
		if (node->getRight() != NULL) preorder(node->getRight());
	}
}

void BinaryTree::postorder(BinaryNode* node)
{
	if (node != NULL) {
		if (node->getLeft() != NULL) postorder(node->getLeft());
		if (node->getRight() != NULL) postorder(node->getRight());
		cout << node->getData() << endl;
		//cout << (char)(node->getData());
	}
}
void BinaryTree::levelorder()
{
	cout << endl << "levelorder: ";
	if (!isEmpty()) {
		//queue<int> q;
		queue<BinaryNode*> q;
		q.push(root);
		while (!q.empty()) {
			BinaryNode* n = q.front();
			q.pop();
			if (n != NULL) {
				cout << " [" << n->getData() << "] ";
				q.push(n->getLeft());
				q.push(n->getRight());
			}
		}
	}
	printf("\n");
}

int BinaryTree::evaluate(BinaryNode* node)
{
	if (node == NULL) return 0;
	if (node->isLeaf()) return node->getData();
	else
	{
		int op1 = evaluate(node->getLeft());
		int op2 = evaluate(node->getRight());
		switch (node->getData())
		{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
}



/*


BinSrchTree 이진탐색트리 클래스


*/

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { }
	~BinSrchTree(void) { }

	BinaryNode* search(int key);
	BinaryNode* search(BinaryNode* n, int key);

	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);

	void remove(int key);
	void remove(BinaryNode* parent, BinaryNode* node);
};

BinaryNode* BinSrchTree::search(int key) {
	BinaryNode* node = search(root, key);  //!!! parent class변수: root=> protected
	if (node != NULL)
		cout << "탐색 성공 : 키 값이 " << node->getData()
		<< " 인 노드 = 0x " << node << endl;
	else	cout << "탐색 실패 : 키값이 " << key << "인 노드 없음 " << endl;
	return node;
}

BinaryNode* BinSrchTree::search(BinaryNode* n, int key) {
	if (n == NULL) return NULL;
	if (key == n->getData()) return n;
	else if (key < n->getData()) return search(n->getLeft(), key);
	else return search(n->getRight(), key);
}

void BinSrchTree::insert(BinaryNode* n) {
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n) {
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

void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node) {

	// case 1: 제거 노드가 단말인 경우
	if (node->isLeaf()) { // 제거 노드가 root인 경우  
		if (parent == NULL) root = NULL;
		else {  	  // 제거 노드가 left child
			if (parent->getLeft() == node)
				// left child 제거
				parent->setLeft(NULL);
			else 	 // 제거 노드가 right child
											 // right child 제거
				parent->setRight(NULL);
		}
	}
	// case 2: 삭제하려는 노드가 서브트리 중 하나만 가지고 있는 경우
	else if (node->getLeft() == NULL || node->getRight() == NULL) {
		// 삭제 노드가 right child를 가지는 경우
		BinaryNode* child = (node->getLeft() != NULL)
			? node->getLeft() : node->getRight();
		if (node == root) root = child;   //삭제 노드가 root면,
		//root 삭제하고 child를 root로 !
		else {
			if (parent->getLeft() == node)  //부모 노드의 왼쪽 자식 제거
				parent->setLeft(child);
			else 			//부모 노드의 오른쪽 자식 제거
				parent->setRight(child);
		}
	}
	// case 3
	else {// 한번 오른쪽으로 가서 계속 왼쪽으로 가면 leftmost node
		BinaryNode* succp = node;
		BinaryNode* succ = node->getRight();
		while (succ->getLeft() != NULL) {
			succp = succ;
			succ = succ->getLeft();
		}

		if (succp->getLeft() == succ)
			succp->setLeft(succ->getRight());
		else
			succp->setRight(succ->getRight());

		node->setData(succ->getData());
		node = succ;  // for deleting the node
	}
	delete node;
}


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

bool BinaryTree::isBST(BinaryNode* node)
{
	if (node == NULL)
	{
		return true;
	}

	if (node->getLeft() != NULL && maxValue(node->getLeft()) >= node->getData()) // 왼쪽 노드가 비어있지 않고 root보다 클 때
	{
		return false;
	}

	
	if (node->getRight() != NULL && minValue(node->getRight()) <= node->getData()) //오른쪽 노드가 비어있지 않고 root보다 작을 때
	{
		return false;
	}

	//#3
	// 왼쪽과 오른쪽 서브트리도 BST인지 확인
	if (!isBST(node->getLeft()) || !isBST(node->getRight()))
	{
		return false;
	}

	return true;

}
int main() {
	// cout<< min(56, NULL)<<endl; // 0
	// cout << min(56, 56) << endl; // 56

	int N;
	BinaryTree bt;
	vector<BinaryNode*> v;
	

	//input data 읽기
	cin >> N;
	v.resize(N+1); //N이 아니라 N+1
	for (int i = 1; i <= N; i++)
	{
		v[i] = new BinaryNode(i); // 포인터에 객체 할당
	}


	
	//binary tree 생성
	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;

		if (left != '.')
		{
			v[root - '0']->setLeft(v[left - '0']);
		}
		else
		{
			v[root - '0']->setLeft(NULL);
		}

		if (right != '.')
		{
			v[root - '0']->setRight(v[right - '0']);
		}
		else
		{
			v[root - '0']->setRight(NULL);
		}

		if (i == 0) { bt.setRoot(v[root - '0']); } //char형을 int형으로

		
	}
	

	
	//BT인지 BST인지 체크하기
	
	if (bt.isBST(bt.getRoot())) cout << "\n1";
	else cout << "\n0";
	

	return 0;
}
