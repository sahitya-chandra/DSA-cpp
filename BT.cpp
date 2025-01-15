#include <bits/stdc++.h>
using namespace std;

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

//O(n) //DFS
void preOrder(Node* node) {
	if (node == NULL) {
		return;
	}

	cout<<node->data<<" ";
	preOrder(node->left);
	preOrder(node->right); 
}

void inOrder(Node* node) {
	if (node == NULL) {
		return;
	}

	inOrder(node->left);
	cout<<node->data<<" ";
	inOrder(node->right); 
}

void postOrder(Node* node) {
	if (node == NULL) {
		return;
	}

	postOrder(node->left);
	postOrder(node->right); 
	cout<<node->data<<" ";
}

//BFS
void levelOrder(Node* node) {
	vecto
}

int main() {

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(5);
}

