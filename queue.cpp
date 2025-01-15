#include <bits/stdc++.h>
using namespace std;

// queue using Array (array with fixed size)
// assuming that the queue will at max have fixed no. elements

class Queue {
private:
    int front, rear, capacity, currSize;
    int* arr;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        currSize = 0;
    }

    // Push function to add element to the queue
    void push(int value) {

        if (currSize == capacity) {
	      	cout << "Queue is full\nExiting..." << endl;
	    }

	    if (currSize == 0) {
		    front = 0;
		    rear = 0;
	    } else {
	    	rear = (rear + 1) % capacity;
	    }

	    arr[rear] = value;
	    cout << "The element pushed is " << value << endl;
	    currSize++;	
    }

    // Pop function to remove element from the queue
    int pop() {
        if (currSize == 0) {
      		cout << "Queue Empty\nExiting..." << endl;
    	}

	    int popped = arr[front];

	    if (currSize == 1) {
		    front = -1;
		    rear = -1;
	    } else {
	      front = (front + 1) % capacity;
	    }

	    currSize--;
	    return popped;
    }

    // Top function to get the front element of the queue
    int top() {
        if (currSize == 0) {
      		cout << "Queue is Empty" << endl;
    	}
    	return arr[front];
    }

    // Size function to get the current size of the queue
    int size() {
        return currSize;
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;
    }
};

// Queue using LL

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = nullptr;
        }


        Node(int data, Node* next) {
            data = data;
            next = next;
        }
};

class QueueLL {
	public:
		Node* start = nullptr;
		Node* end = nullptr;
		int sizee = 0;

		void push(int data) {
			Node* temp = new Node(data);

			if (start == nullptr) {
				start = temp;
				end = temp;
	
			} else {
				end->next = temp;
				cout<<end->data<<endl;
			}

			sizee += 1;
		}

		void pop() {

			if (start == nullptr) {
				cout<<"empty";
			}

			Node* temp = start;
			start = temp->next;
			delete temp;
			sizee -= 1; 
		}

		int top() {
			if (start == nullptr) return 0;
			return start->data;
		}

		int size() {
			// cout<<start;
			return sizee;
		}
};

int main() {
    // Queue q(5);
    QueueLL q;

    q.push(10);
    q.push(20);
    cout << "Top element: " << q.top() << endl;  // Output: 10
    cout << "Queue size: " << q.size() << endl;  // Output: 2

    q.pop();
    cout << "Top element after pop: " << q.top() << endl;  // Output: 20
    cout << "Queue size after pop: " << q.size() << endl;  // Output: 1

    q.push(30);
    q.push(40);
    // q.push(50);
    // q.push(60);

    q.pop();
    cout<<q.top()<<endl;
    cout << "Queue size after another pop: " << q.size() << endl;  // Output: 0
    // q.pop();
    cout<<q.top()<<endl;
    // cout<<q.size()<<endl;
    return 0;
}


// class Queue {
// private:
//     int front, rear, capacity;
//     int* arr;

// public:
//     Queue(int capacity) {
//         this->capacity = capacity;
//         arr = new int[capacity];
//         front = 0;
//         rear = -1;
//     }

//     // Push function to add element to the queue
//     void push(int value) {
//         if (rear == capacity - 1) {
//             cout << "Queue overflow\n";
//             return;
//         }
//         arr[++rear] = value;
//     }

//     // Pop function to remove element from the queue
//     void pop() {
//         if (front > rear) {
//             cout << "Queue underflow\n";
//             return;
//         }
//         front++;
//     }

//     // Top function to get the front element of the queue
//     int top() {
//         if (front > rear) {
//             cout << "Queue is empty\n";
//             return -1;
//         }
//         return arr[front];
//     }

//     // Size function to get the current size of the queue
//     int size() {
//         return (rear - front + 1);
//     }

//     // Destructor to free allocated memory
//     ~Queue() {
//         delete[] arr;
//     }
// };

// int main() {
//     Queue q(5);

//     q.push(10);
//     q.push(20);
//     cout << "Top element: " << q.top() << endl;  // Output: 10
//     cout << "Queue size: " << q.size() << endl;  // Output: 2

//     q.pop();
//     cout << "Top element after pop: " << q.top() << endl;  // Output: 20
//     cout << "Queue size after pop: " << q.size() << endl;  // Output: 1

//     q.pop();
//     cout << "Queue size after another pop: " << q.size() << endl;  // Output: 0
//     return 0;
// }
