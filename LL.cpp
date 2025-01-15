#include <bits/stdc++.h>
using namespace std;

class Node {

	public:
		int data;
		Node* next;

		Node(int data1, Node* next1) {
			data = data1;
			next = next1;
		}

		Node(int data2) {
			data = data2;
			next = nullptr;
		}
};

Node* convertArr2LL(vector<int> &arr) {
	Node* head = new Node(arr[0]);
	Node* mover = head;

	for(int i = 1; i<arr.size(); i++) {
		Node* temp = new Node(arr[i]);
		mover->next = temp;
		// cout<<mover->next<<" "<<mover->data<<endl;
		mover = temp;
		
	}
	cout<<"head: "<<head<<endl;
	return head;
}

void printLL(Node* head) {

	Node* currentNode = head;

	while(currentNode != NULL) {
		// cout<<currentNode->data<<endl;
		currentNode = currentNode->next;
	}
	cout<<endl;
}

//deletion

Node* removeHead(Node* head) {
	if(head == NULL) return head;
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

Node* removeTail(Node* head) {
	if(head == NULL || head->next == NULL) return NULL;

	Node* temp = head;

	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	free(temp->next);
	temp->next = nullptr;
	return head;
}

Node* removePosition(Node* head, int k) {
	if(head == NULL) return head;
	if(k == 1) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	int count = 0;
	Node* temp = head;
	Node* prev = NULL;
	while(temp != NULL) {
		count++;
		if(count == k) {
			prev->next = prev->next->next;
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	// cout<<prev->data<<count<<endl;
	return head;
}

Node* removeValue(Node* head, int val) {
	if(head == NULL) return head;
	if(head->data == val) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	Node* temp = head;
	Node* prev = NULL;
	while(temp != NULL) {
		if(temp->data == val) {
			prev->next = prev->next->next;
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	// cout<<prev->data<<endl;
	return head;
}

//insertion

Node* insertHead(Node* head, int val) {
	Node* temp = new Node(val, head);
	// return new Node(val, head);
	return temp;
}

Node* insertTail(Node* head, int val) {
	if(head == NULL) return new Node(val);
	Node* temp = head;
	Node* newNode = new Node(val);
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}

Node* insertPosition(Node* head, int val, int k) {
	if(head == NULL) {
		// return k == 1 ? new Node(val) : head;
		if(k == 1) {
			return new Node(val);
		} else {
			return head;
		}
	}

	if(k == 1) {
		return new Node(val, head);
	}

	int count = 0;
	Node* temp = head;
	while(temp != NULL) {
		count++;
		if(count == (k-1)) {
			Node* x = new Node(val, temp->next);
			temp->next = x;
			break;
		}
		temp = temp->next;	
	}
	return head;
}

Node* insertBeforeValue(Node* head, int el, int val) {
	if(head == NULL) return NULL;

	if(head->data == val) {
		return new Node(el, head);
	}

	Node* temp = head;
	while(temp->next != NULL) {
		if(temp->next->data == val) {
			Node* x = new Node(el, temp->next);
			temp->next = x;
			break;
		}
		temp = temp->next;	
	}
	return head;
}

int main() {
	
	vector<int> arr = {1, 2, 3, 4, 5};
	Node* head = convertArr2LL(arr);
	// head = removeHead(head);
	// head = removeTail(head);
	// head = removePosition(head, 2);
	// head = removeValue(head, 4);
	// head = insertHead(head, 7);
	// head = insertTail(head, 10);
	// head = insertPosition(head, 222, 1
	// head = insertBeforeValue(head, 222, 3);	
	printLL(head);

	

	// cout<<head->data<<endl;
	// cout<<head->next<<endl;
	// cout<<head;

	return 0;
}




