#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack Implementation
class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node{value, top};
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! No elements to pop.\n";
            return;
        }
        cout << "Popped " << top->data << "from the stack"<< endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peek() const {
        if (top) {
            cout << "Top element is: " << top->data << endl;
        } else {
            cout << "Stack is empty.\n";
        }
    }

    void display() const {
        Node* current = top;
        cout << "Stack elements (top to bottom): ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Queue Implementation
class Queue {
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! No elements to dequeue.\n";
            return;
        }
        cout << "Dequeued " << front->data << "from the queue" << endl;
        Node* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
    }

    void peek() const {
        if (front) {
            cout << "Front Element is: " << front->data << endl;
        } else {
            cout << "Queue is empty.\n";
        }
    }

    void display() const {
        Node* current = front;
        cout << "Queue (front to rear): ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Menu-Driven Interface
int main() {
    Stack stack;
    Queue queue;
    int choice, value;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "\n1. Push (Stack)\n2. Pop (Stack)\n3. Peek (Stack)\n4. Display (Stack)\n"
                "5. Enqueue (Queue)\n6. Dequeue (Queue)\n7. Peek (Queue)\n8. Display (Queue)\n9. Exit\n";
        cout << "Enter your choice: " << endl;
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
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
