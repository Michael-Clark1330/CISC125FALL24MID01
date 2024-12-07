#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No elements to pop.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped " << top->data << " from the stack.\n";
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* current = top;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear) {
            rear->next = newNode;
        }
        rear = newNode;
        if (!front) {
            front = rear;
        }
        cout << "Enqueued " << value << " into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! No elements to dequeue.\n";
            return;
        }
        Node* temp = front;
        cout << "Dequeued " << front->data << " from the queue.\n";
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements (front to rear): ";
        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// Menu-driven program
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
        cout << "0. Exit\n";
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
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
