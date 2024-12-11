#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {};//Constructor
};
class linkedList{
private:
    Node* head; //Head of list
public:
    linkedList() : head(nullptr) {};//Constructor 

    //---Functions---//
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);//Create new node
        newNode->next = head;//set the 'next' address to the current head
        head = newNode;//sets the head equal to the new Node
    } 

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);//Create new node
        Node* temp = head;//Create a temp node equal to the head to help us search through the list

        while (temp->next != nullptr) { //goes through each 'next' till we reach one that equals NULL which is the end
            temp = temp->next;
        }
        temp->next = newNode;//sets the last node 'next' to the new node
    }
    void insertAfter(int searchValue, int newValue) {
        Node* temp = head;
        Node* newNode = new Node(newValue);
        while (temp != nullptr && temp->data != searchValue) { //checks the list till you reach the end, or till the data matches the value we are searching for
            temp = temp->next;
        }
        if (temp != nullptr) {
            newNode->next = temp->next;//sets the 'next' link of the newNode to the TARGET 'next' link; right now they BOTH point to the next node or NULL
            temp->next = newNode;//changes the 'next' link in the temp node to the address of the newNode: newNode still points to the next node
        }
        else {
            cout << "Error Value Not Found" << endl;
        }
    }
    void deleteByValue(int value) {
        Node* temp = head;//start at the beginning of list
        while (temp->next != nullptr && temp->next->data != value) {//looks through the list till you reach the end or the data matches
            temp = temp->next;
        }
        //The temp Node is currently equal to the node BEFORE the value node we want to delete
        if (temp->next != nullptr) {
            Node* toDelete = temp->next;//sets the new node to the node we are trying to delete
            temp->next = temp->next->next;//sets the next node link from the temp node to the node AFTER the node we are going to delete
            delete toDelete;//deletes the target node
        }
        else {
            cout << "Error Value Not Found" << endl;
        }
    } 
    void deleteFirst() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;//sets temp to head
        head = head->next;//sets head to the next node
        delete temp;//delete head/first node
    } 
    void deleteLast() {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    int search(int value) {
        Node* temp = head;
        int pos = 0;//keeps track of what number pos you are at
        while (temp != nullptr) {
            if (temp->data == value) {//if the current node equals the value we are looking for, returns pos
                return pos;
            }
            temp = temp->next;//if not, we move on to the next node and go up in the pos
            pos++;
        }
        return -1;//if nothing is found return -1
    } 
    void display() {
        Node* temp = head;
        while (temp != nullptr) {//go through all the nodes till one is a NULL node
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    } 
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        //these three^^ helps us keep track of the each pos
        while (current != nullptr) {//check and make sure the current one isnt NULL/ at the end
            next = current->next;//save the next node
            current->next = prev;//reverse the current node's 'next' link
            prev = current;//move prev to current
            current = next;//current to next
        }
        head = prev;

        Node* temp = head;
        while (temp != nullptr) {//go through all the nodes till one is a NULL node
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    int choice = 0, search, value;
    linkedList list;
    while (choice != 10) {
        cout << "Single Linked List Operations:" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Value" << endl;
        cout << "4. Delete by Value" << endl;
        cout << "5. Delete First Node" << endl;
        cout << "6. Delete Last Node" << endl;
        cout << "7. Search for Value" << endl;
        cout << "8. Display List" << endl;
        cout << "9. Reverse List" << endl;
        cout << "10. Exit" << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter the value to insert at the end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter search value: ";
                cin >> search;
                cout << "Enter the value to insert after: ";
                cin >> value;
                list.insertAfter(search, value);
                break;
            case 4:
                cout << "Enter value you want to delete: ";
                cin >> value;
                list.deleteByValue(value);
                break;
            case 5:
                cout << "Deleting First Node..." << endl;
                list.deleteFirst();
                break;
            case 6:
                cout << "Deleting Last Node..." << endl;
                list.deleteLast();
                break;
            case 7:
                cout << "Enter the value to search: ";
                cin >> value;
                cout << "POS: " << list.search(value) << endl;
                break;
            case 8:
                cout << "Current Linked List: ";
                list.display();
                cout << endl;
                break;
            case 9:
                cout << "Reverse Linked List: ";
                list.reverse();
                cout << endl;
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;

        }
    }
    

}
