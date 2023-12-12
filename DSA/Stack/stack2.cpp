#include <iostream>
using namespace std;
// Node structure to represent elements in the linked list
struct Node {
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack(){
        top=NULL;
    }

    ~Stack() {
        // Destructor to free memory when the stack is destroyed
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the stack is empty
    bool empty() {
        return top == nullptr; // return  true or false
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop an element from the stack
    void pop() {
        if (!empty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "Error: Cannot pop from an empty stack." << endl;
        }
    }

    // Get the top element of the stack
    int peek()  {
        if (!empty()) {
            return top->data;
        } else{
        return -1;
        }
    }
};

int main() {
    // Example usage of the Stack class
    Stack intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element: " << intStack.peek() << endl;

    intStack.pop();
    cout << "Top element after pop: " << intStack.peek() << endl;

    intStack.pop();
    intStack.pop(); // Popping the last element

    // Attempting to pop from an empty stack (an error message will be printed)
    intStack.pop();

    return 0;
}
