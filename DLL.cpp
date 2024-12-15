#include <bits/stdc++.h>
using namespace std;

class Node {

	public:
		int data;
		Node* next;
		Node* back;

		Node(int data1, Node* next1, Node* back1) {
			data = data1;
			next = next1;
			back = back1;
		}

		Node(int data2) {
			data = data2;
			next = nullptr;
			back = nullptr;
		}
};

Node* convertArr2DLL(vector<int> &arr) {
	Node* head = new Node(arr[0]);
	Node* prev = head;

	for(int i = 1; i<arr.size(); i++) {
		Node* temp = new Node(arr[i], nullptr, prev);
		prev->next = temp;
		prev = temp;
	}

	return head;
}

void printDLL(Node* head) {

	Node* currentNode = head;

	while(currentNode != NULL) {
		cout<<currentNode->data<<endl;
		currentNode = currentNode->next;
	}
	cout<<endl;
}

//deletion

Node* deleteHead(Node* head) {
	if(head == NULL || head->next == NULL) return NULL;

	Node* prev = head;
	head = head->next;
	head->back = nullptr;
	prev->next = nullptr;
	delete prev;

	return head;
}

Node* deleteTail(Node* head) {
	if(head == NULL || head->next == NULL) return NULL;

	Node* tail = head;
	while(tail->next != NULL) {
		tail = tail->next;
	}
	Node* prev = tail->back;
	prev->next = nullptr;
	tail->back = nullptr;
	delete tail;

	return head;
}

Node* deleteKthElement(Node* head, int k) { // k should not be greater then array length
	if(head == NULL || head->next == NULL) return NULL;

	int count = 0;
	Node* kNode = head;
	while(kNode != NULL) {
		count++;
		if(count == k) break;
		kNode = kNode->next;
	}

	Node* prev = kNode->back;
	Node* front = kNode->next;

	if(prev == NULL && front == NULL) return NULL;

	else if(prev == NULL) {
		return deleteHead(head);
	}
	else if(front == NULL) {
		return deleteTail(head);
	}
	prev->next = front;
	front->back = prev;

	kNode->next = nullptr;
	kNode->back = nullptr;

	delete kNode;
	return head;
}

void deleteNode(Node* temp) { //never ask to delete the head 
	Node* prev = temp->back;
	Node* front = temp->next;

	if(front == NULL) {
		prev->next = nullptr;
		temp->back = nullptr;
		free(temp);
		return;
	}

	prev->next = front;
	front->back = prev;

	temp->next = temp->back = nullptr;
	free(temp);
} 

//insertion before

Node* insertBeforeHead(Node* head, int val) {
	Node* newHead = new Node(val, head, nullptr);
	head->back = newHead;

	return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
	if(head->next == NULL) {
		return insertBeforeHead(head, val);
	}

	Node* tail = head;
	while(tail->next != NULL) {
		tail = tail->next;
	}

	Node* prev = tail->back;
	Node* newNode = new Node(val, tail, prev);
	prev->next  = tail->back = newNode;

	return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val) {
	if(k == 1) {
		return insertBeforeHead(head, val);
	}

	Node* temp = head;
	int count = 0;
	while(temp != NULL) {
		count++;
		if(count == k) break;
		temp = temp->next;
	}

	Node* prev = temp->back;
	Node* newNode = new Node(val, temp, prev);
	prev->next = newNode;
	temp->back = newNode;

	return head;
}

void insertBeforeNode(Node* node, int val) { // before head will not be inserted 
	Node* prev = node->back;
	Node* newNode = new Node(val, node, prev);
	prev->next = newNode;
	node->back = newNode;
}

int main() {

	vector<int> arr = {6, 7, 8, 9, 10};

	Node* head = convertArr2DLL(arr);
	// head = deleteHead(head);
	// head = deleteTail(head);
	// head = deleteKthElement(head, 4);
	// deleteNode(head->next);

	// head = insertBeforeHead(head, 12);
	// head = insertBeforeTail(head, 12);
	// head = insertBeforeKthElement(head, 5, 15);
	insertBeforeNode(head->next->next, 10);

	printDLL(head);

	return 0;
}