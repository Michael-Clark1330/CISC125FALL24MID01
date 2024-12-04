#include <iostream>
using namespace std;

// Node structure for linked list
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

    ~Stack() {
        while (top) pop();
    }

    void push(int value) {
        Node* newNode = new Node{value, top};
        top = newNode;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from an empty stack.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from the stack.\n";
        delete temp;
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek.\n";
            return;
        }
        cout << "Top of stack: " << top->data << endl;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack contents (top to bottom): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() const {
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

    ~Queue() {
        while (front) dequeue();
    }

    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
        cout << "Enqueued " << value << " into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue from an empty queue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        cout << "Dequeued " << temp->data << " from the queue.\n";
        delete temp;
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek.\n";
            return;
        }
        cout << "Front of queue: " << front->data << endl;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue contents (front to rear): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    Stack stack;
    Queue queue;

    int choice, value;
    do {
        cout << "\nMenu:\n"
             << "1. Push (Stack)\n"
             << "2. Pop (Stack)\n"
             << "3. Peek (Stack)\n"
             << "4. Display (Stack)\n"
             << "5. Enqueue (Queue)\n"
             << "6. Dequeue (Queue)\n"
             << "7. Peek (Queue)\n"
             << "8. Display (Queue)\n"
             << "9. Exit\n"
             << "Enter your choice: ";
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
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
