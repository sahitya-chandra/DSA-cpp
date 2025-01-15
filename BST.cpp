#include <bits/stdc++.h>
using namespace std;

//logbase2(n) height

class Node {
	public:

		int data;
		Node* left;
		Node* right;

		Node(int data) {
			data = data;
			left = right = nullptr;
		} 
};

Node* search(Node* root, int val) {
	while(root != NULL && root->data != val) {
		root = val < root->data ? root->left : root->right;
	}

	return root;
}

Node* insertIntoBST(Node* root, int val) {
	if (root == NULL) return new Node(val);
	Node* cur = root;
	while (true) {
		if(cur->data <= val) {
			if(cur->right != NULL) cur = cur->right;
			else {
				cur->right = new Node(val);
				break;
			}
		} else {
			if(cur->left != NULL) cur = cur->left;
			else {
				cur->left = new Node(val);
				break;
			}

		}
	} 
	return root;
}

//---------------------

Node* findLastRight(Node* root) {
	if(root->right == NULL) {
		return root;
	}
	return findLastRight(root->right);
}

Node* helper(Node* root) {
	if (root->left == NULL) {
		return root->right;
	} else if (root->right == NULL) {
		return root->left;
	}
	Node* rightChild = root->right;
	Node* lastRight = findLastRight(root->left);
	lastRight->right = rightChild;
	return root->left;
}

Node* deleteNode(Node* root, int key) {
	if(root == NULL) {
		return NULL;	
	}

	if (root->data == key) {
		return helper(root);
	}

	Node* dummy = root;
	while(root != NULL) {
		if(root->data > key) {
			if(root->data != NULL && root->left->data == key) {
				root->left = helper(root->left);
				break;
			} else {
				root = root->left;
			}

		} else {
			if(root->right != NULL && root->right->data == key) {
				root->right = helper(root->right);
				break;
			} else {
				root = root->right;
			}
		}
	}
	return dummy;
}





int main() {

}