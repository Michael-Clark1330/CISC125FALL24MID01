#include <iostream>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList Class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~LinkedList() {
        while (head) {
            deleteFirst();
        }
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert after a given value
    void insertAfter(int searchValue, int newValue) {
        Node* temp = head;
        while (temp && temp->data != searchValue) {
            temp = temp->next;
        }
        if (temp) {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Value " << searchValue << " not found in the list." << endl;
        }
    }

    // Delete by value
    void deleteByValue(int value) {
        if (!head) return;
        if (head->data == value) {
            deleteFirst();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        } else {
            cout << "Value " << value << " not found in the list." << endl;
        }
    }

    // Delete the first node
    void deleteFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete the last node
    void deleteLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Search for a value
    int search(int value) {
        Node* temp = head;
        int position = 0;
        while (temp) {
            if (temp->data == value) return position;
            temp = temp->next;
            position++;
        }
        return -1; // Value not found
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    // Reverse the list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

// Main Function
int main() {
    LinkedList list;
    int choice, value, searchValue;

    do {
        cout << "\nSingle Linked List Operations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Value\n";
        cout << "4. Delete by Value\n";
        cout << "5. Delete First Node\n";
        cout << "6. Delete Last Node\n";
        cout << "7. Search for Value\n";
        cout << "8. Display List\n";
        cout << "9. Reverse List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter the value to search: ";
            cin >> searchValue;
            cout << "Enter new value to insert: ";
            cin >> value;
            list.insertAfter(searchValue, value);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteByValue(value);
            break;
        case 5:
            list.deleteFirst();
            break;
        case 6:
            list.deleteLast();
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            int pos;
            pos = list.search(value);
            if (pos != -1)
                cout << "Value found at position: " << pos << endl;
            else
                cout << "Value not found in the list." << endl;
            break;
        case 8:
            list.display();
            break;
        case 9:
            list.reverse();
            break;
        case 10:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
