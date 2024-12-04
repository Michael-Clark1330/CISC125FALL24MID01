#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow! Cannot pop from an empty stack.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped " << top->data << " from the stack.\n";
        top = top->next;
        delete temp;
    }

    void peek() const {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element is: " << top->data << "\n";
    }

    void display() const {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* current = top;
        cout << "Stack elements (top to bottom): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into the queue.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow! Cannot dequeue from an empty queue.\n";
            return;
        }
        Node* temp = front;
        cout << "Dequeued " << front->data << " from the queue.\n";
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // Queue is now empty
        }
        delete temp;
    }

    void peek() const {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element is: " << front->data << "\n";
    }

    void display() const {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        cout << "Queue elements (front to rear): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack stack;
    Queue queue;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push (Stack)\n";
        cout << "2. Pop (Stack)\n";
        cout << "3. Peek (Stack)\n";
        cout << "4. Display (Stack)\n";
        cout << "5. Enqueue (Queue)\n";
        cout << "6. Dequeue (Queue)\n";
        cout << "7. Peek (Queue)\n";
        cout << "8. Display (Queue)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push onto the stack: ";
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
            cout << "Enter value to enqueue into the queue: ";
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
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
