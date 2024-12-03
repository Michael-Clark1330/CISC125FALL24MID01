//Noah Sumner 1141993
#include <iostream>
using namespace std;

//Class that creates a node
class Node {
public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
};

//Class that creates a linked list
class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    //Add an element to the top of the stack
    void Push(int value) {
        Node* N = new Node();
        N->data = value;
        N->next = NULL;
        if (head == NULL) {
            head = N;
            cout << "Pushed " << value << " onto the stack." << endl;
            return;
        }
        Node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = N;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    //Remove and display the top element of the stack
    void Pop() {
        if (!head) {
            cout << "Stack is empty!" << endl;
            return;
        }
        if (!head->next) {
            int d = head->data;
            delete head;
            head = NULL;
            cout << "Popped " << d << " from the stack." << endl;
            return;
        }
        Node* t = head;
        while (t->next->next) {
            t = t->next;
        }
        int d = t->next->data;
        delete t->next;
        t->next = NULL;
        cout << "Popped " << d << " from the stack." << endl;
    }

    //Display the top element without removing it
    void Peek() {
        if (!head) {
            cout << "Stack is empty!" << endl;
            return;
        }
        if (!head->next) {
            cout << "Top element is: " << head->data << endl;
            return;
        }
        Node* t = head;
        while (t->next->next) {
            t = t->next;
        }
        cout << "Top element is: " << t->next->data << endl;
    }

    //Add an element to the rear of the queue
    void Enqueue(int value) {
        Node* N = new Node();
        N->data = value;
        N->next = NULL;
        if (head == NULL) {
            head = N;
            cout << "Enqueued " << value << " onto the queue." << endl;
            return;
        }
        Node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = N;
        cout << "Enqueued " << value << " onto the queue." << endl;
    }

    //Remove and display the front element of the queue
    void Dequeue() {
        if (!head) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* t = head;
        int d = t->data;
        head = head->next;
        delete t;
        cout << "Dequeued " << d << " from the queue." << endl;
    }

    //Display the front element without removing it
    void Peak() {
        if (!head) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* t = head;
        cout << "Front element is: " << t->data << endl;
    }

    //function that reverses the list perminately
    void reverse() {
        Node *t = head, *p = NULL, *q;
        if (t == NULL) {
            return;
        }
        while (t != NULL) {
            q = t->next;
            t->next = p;
            p = t;
            t = q;
        }
        head = p;
    }
    
    //Show all elements from top to bottm (stack)
    void DisplayS() {
        reverse();
        Node *t = head;
        if (t == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        else if (t != NULL) {
            cout << "Stack elements (top to bottom): ";
        }
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
        reverse();
    }

    //Show all elements from front to rear (queue)
    void DisplayQ() {
        Node *t = head;
        if (t == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        else if (t != NULL) {
            cout << "Queue elements (front to rear): ";
        }
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }

    //function that deletes the list
    void deleteL() {
        Node* t = head;
        Node* next;
        while (t != NULL) {
            next = t->next;
            delete t;
            t = next;
        }
        head = NULL;
    }
};

//declarations
int go = 1, in1, in2, value;

int main() {
    LinkedList Stack;
    LinkedList Queue;


    //Prompt for user input
    while (go == 1 ) {
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
        cout << "Enter your choice: ";
        cin >> in1;

        //Each case activates a function in LinkedList
        switch(in1) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                Stack.Push(value);
                break;
            case 2:
                Stack.Pop();
                break;
            case 3:
                Stack.Peek();
                break;
            case 4:
                Stack.DisplayS();
                break;
            case 5:
                cout << "Enter value to enqueue: ";
                cin >> value;
                Queue.Enqueue(value);
                break;
            case 6:
                Queue.Dequeue();
                break;
            case 7:
                Queue.Peak();
                break;
            case 8:
                Queue.DisplayQ();
                break;
            case 9:
                cout << "Exiting Program...\n\n";
                Stack.deleteL();
                Queue.deleteL();
                go = 0;
                break;
            default:
                cout << "Please enter a valid number...\n";
        }
    }
    return 0;
};
