#include <bits/stdc++.h>
using namespace std;

// stack using Array (array with fixed size)
// assuming that the stack will at max have 10 elements

class StackArr {
    private:
        int topIndex;
        int capacity;
        int* arr;

    public:
        StackArr(int capacity) {
            this->capacity = capacity;
            arr = new int[capacity];
            topIndex = -1;
        }

        // Push function to add element to the stack
        void push(int value) {
            if (topIndex == capacity - 1) {
                cout << "Stack overflow\n";
                return;
            }
            topIndex += 1;
            arr[topIndex] = value;
        }

        // Pop function to remove element from the stack
        void pop() {
            if (topIndex == -1) {
                cout << "Stack underflow\n";
                return;
            }
            topIndex--;
        }

        // Top function to get the top element of the stack
        int top() {
            if (topIndex == -1) {
                cout << "Stack is empty\n";
                return -1;
            }
            return arr[topIndex];
        }

        // Size function to get the current size of the stack
        int size() {
            return topIndex + 1;
        }

        // Destructor to free allocated memory
        ~StackArr() {
            delete[] arr;
        }
};

// Stack using LL

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

class StackLL {
    public:
        Node* topEl = nullptr;
        int sizee = 0;

        void push(int data) {
            Node* temp = new Node(data);
            temp->next = topEl;
            topEl = temp;
            sizee += 1;
        }

        void pop() {
            Node* temp = topEl;
            topEl = topEl->next;
            delete temp;
            sizee = sizee - 1;
        }

        int top() {
            return topEl->data;
        }

        int size() {
            return sizee;
        }

};

int main() {
    // StackArr s(5);
    StackLL s;

    s.push(10);
    s.push(20);
    cout << "Top element: " << s.top() << endl;  // Output: 20
    cout << "Stack size: " << s.size() << endl;  // Output: 2

    s.pop();
    s.push(30);
    cout << "Top element after pop: " << s.top() << endl;  // Output: 10
    cout << "Stack size after pop: " << s.size() << endl;  // Output: 1
    s.push(40);
    // s.push(50);
    // s.push(60);

    s.pop();
    cout << "Stack size after another pop: " << s.size() << endl;  // Output: 0
    return 0;
}
