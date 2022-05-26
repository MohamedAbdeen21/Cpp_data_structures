#include <bits/stdc++.h>
using namespace std;

class BNode{
	public:
	int value;
	BNode* right;
	BNode* left;
	BNode() : value(-1),right(NULL),left(NULL){}
	BNode(int v) : value(v), right(NULL),left(NULL) {}
	BNode(int v, BNode* left, BNode* right): value(v), right(right),left(left){}
};
//
//			5
//		       / \
//		      4    3
//			  / \
//		         2   1
//

class BTree{
	public:
		BNode* root;
		BTree(int value){root = new BNode(value);}
		BNode* left(BNode* node);
		BNode* right(BNode* node);
		BNode* parent(BNode* node);
		bool isRoot(BNode* node) {return node == root;}
		bool isExternal(BNode* node) {return node -> left == NULL && node -> right == NULL;}
		int get_size();
		bool empty() {return root -> value != -1;}
};



int main(){
	BTree root(5);
	root.root -> left =new BNode(4);
	BNode* newNode1 = new BNode(2);
	BNode* newNode2 = new BNode(1);
	root.root -> right = new BNode(3,newNode1,newNode2);

	stack <BNode*> stack;

	stack.push(root.root);
	BNode* curr = NULL;
	while (!stack.empty()){
		curr = stack.top();
		stack.pop();
		cout << curr -> value << " ";
	
		if (curr -> left != NULL)
			stack.push(curr -> left);

		if (curr -> right != NULL)
			stack.push(curr -> right);
	}

	return EXIT_SUCCESS;

}
