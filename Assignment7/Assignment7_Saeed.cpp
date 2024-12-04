#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Stack class
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << val << " onto the stack." << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Popped " << top->data << " from the stack." << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top) {
            pop();
        }
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << val << " into the queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued " << front->data << " from the queue." << endl;
        front = front->next;
        if (front == nullptr) rear = nullptr; // If queue becomes empty
        delete temp;
    }

    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements (front to rear): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (front) {
            dequeue();
        }
    }
};

int main() {
    Stack stack;
    Queue queue;
    int choice, value;

    while (true) {
        cout << "--- Menu ---" << endl;
        cout << "1. Push (Stack)" << endl;
        cout << "2. Pop (Stack)" << endl;
        cout << "3. Peek (Stack)" << endl;
        cout << "4. Display (Stack)" << endl;
        cout << "5. Enqueue (Queue)" << endl;
        cout << "6. Dequeue (Queue)" << endl;
        cout << "7. Peek (Queue)" << endl;
        cout << "8. Display (Queue)" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 6:
                queue.dequeue();
                break;
            case 7:
                queue.peek();
                break;
            case 8:
                queue.display();
                break;
            case 9:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}