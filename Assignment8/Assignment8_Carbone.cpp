#include <iostream>
using namespace std;

//Defines linked list node
struct Node {
    int d;
    Node* next;
    Node(int val) : d(val), next(nullptr){}
};

//Merges two linked lists into one
Node* merge(Node* l, Node* r){
    if(!l) return r;
    if(!r) return l;

    //Compares the nodes and merges
    if(l->d <= r->d){
        l->next=merge(l->next, r); //merges rest of left list with right
        return l; //returns left as merged result
    }
    else {
        r->next=merge(l, r->next); //merges rest of right list with left
        return r; //returns right as merged result
    }
}

//Function to split linked list into halves
Node* split(Node* head){
    if(!head || !head->next){ //if list has less than two elements, return null
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) { //Move slow one step, and fast two steps, until fast reaches the end
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secHalf = slow->next; //splits list into two parts
    slow->next = nullptr;
    return secHalf;
}

//Merge sort function for linked list; recursive
Node* mergeSort(Node* head) {
    if(!head || !head->next) {
        return head; //Base case; if list has 0 or 1 element, already sorted.
    }
    //split list into two halves
    Node* secHalf = split(head);

    //Sorts two halves recursively
    head=mergeSort(head);
    secHalf=mergeSort(secHalf);

    //Merge sorted halves, return result
    return merge(head, secHalf);
}

//Allows for input from user
void inputLinkedList(Node*& head, int size){
    cout << "Enter elements: " << endl;
    int val;
    cin >> val;
    head = new Node(val);
    Node* temp = head;
    for(int i = 1; i < size; i++){ //Input rest of elements and link them
        cin >> val;
        temp->next = new Node(val);
        temp=temp->next;
    }
}

//Prints linked list
void printLinkedList(Node* head){
    Node* temp=head;
    cout << "Sort Linked List: ";
    while (temp){
        cout << temp->d << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int size;
    cout << "Enter the size of linked list (1-100): ";
    cin >> size;
    if(size < 1 || size > 100){ //Ensures size cannot exceed 100
        cout << "Invalid size!" << endl;
        return -1;
    }
    Node* head = nullptr;
    inputLinkedList(head, size);
    head = mergeSort(head); //Sorts linked list using merge sort
    printLinkedList(head); //Prints sorted linked list
    return 0;
};