#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------------
// 1. Setting up Nodes and Stacks for future manipulation

struct Node 
{
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
    };

class Stack 
{
private:
    Node* top;
public:
    Stack() : top(NULL) {}
    
//-----------------------------------------------------------------
// 2. Setting up Pushing, Popping, Peeking, and Display elements for Last-In-First-Out and First-In-First-Out and information input later
    
    void push(int value) 
{
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop() 
{
        if (top == NULL) 
{
            cout << "\nStack is empty!" << endl;
            return;
    }
        Node* temp = top;
        cout << "Popped " << top->data << " from the stack." << endl;
        top = top->next;
        delete temp;
    }

    void peek() 
{
        if (top == NULL) 
{
            cout << "Stack is empty!" << endl;
            return;
    }
        cout << "Top element is: " << top->data << endl;
    }

    void display() 
{
        if (top == NULL) 
{
            cout << "Stack is empty!" << endl;
            return;
    }
        Node* temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp) 
{
            cout << temp->data << " ";
            temp = temp->next;
    }
        cout << endl;
}

    ~Stack() 
{
        while (top) 
{
            pop();
    }
    }
};

//-----------------------------------------------------------------
// 3. Devising the queue/enqueue and dequeue incorporated systems 

class Queue 
{
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int val) 
{
        Node* newNode = new Node(val);
        if (rear == NULL) 
{
            front = rear = newNode;
    } else 
{
            rear->next = newNode;
            rear = newNode;
    }
        cout << "Enqueued " << val << " into the queue." << endl;
    }

    void dequeue() 
{
        if (front == NULL) 
{
            cout << "Queue is empty!" << endl;
            return;
    }
        Node* temp = front;
        cout << "Dequeued " << front->data << " from the queue." << endl;
        front = front->next;
        if (front == NULL) rear = NULL; // If queue becomes empty
        delete temp;
    }
//-----------------------------------------------------------------
// 4. Adjusting the queue/enqueue with the positioning tools

    void peek() 
{
        if (front == NULL) 
{
            cout << "Queue is empty!" << endl;
            return;
    }
        cout << "Front element is: " << front->data << endl;
    }

    void display() 
{
        if (front == NULL) 
{
            cout << "Queue is empty!" << endl;
            return;
    }
        Node* temp = front;
        cout << "Queue elements (front to rear): ";
        while (temp) 
{
            cout << temp->data << " ";
            temp = temp->next;
    }
        cout << endl;
    }

    ~Queue() 
{
        while (front) 
{
            dequeue();
    }
    }
};
//-----------------------------------------------------------------
// 5. Main function where the user is finally prompted to input

int main() 
{
    Stack stack;
    Queue queue;
    int choice, val;

    while (true) 
{
        cout << "\n--- Menu ---" << endl;
        cout << "1. Push (Stack)" << endl;
        cout << "2. Pop (Stack)" << endl;
        cout << "3. Peek (Stack)" << endl;
        cout << "4. Display (Stack)" << endl;
        cout << "5. Enqueue (Queue)" << endl;
        cout << "6. Dequeue (Queue)" << endl;
        cout << "7. Peek (Queue)" << endl;
        cout << "8. Display (Queue)" << endl;
        cout << "9. Exit" << endl;
        cout << "\nEnter your choice:";
        cin >> choice;

        switch (choice) 
{
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                stack.push(val);
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
                cin >> val;
                queue.enqueue(val);
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
                cout << "Exiting..." << endl;
                return 0;
            
            default:
                cout << "Try again." << endl;
    }
    }
    return 0;
}