#include <iostream>
using namespace std;

//creates class for node
class Node
{
  public:
    int data;
    Node* next;

    Node(int value)
    {
      data = value;
      next = nullptr;
    }
};

//creates class for stack functions to operate
class Stack
{
  private:
    Node* stackTop;

    public:
      Stack()
      {
        stackTop = nullptr;
      }


//push function
void Push(int value)
{
  Node* newNode;
  newNode = new Node(value);
  newNode->data = value;
  newNode->next = stackTop;
  stackTop = newNode;

    cout << "Pushed " << value << " onto the stack." << endl;
    return;
}

//pop function
void Pop()
{
  Node* temp;

   //if list has values
   if (stackTop != nullptr)
   {
     temp = stackTop;
     cout << "Popped " << stackTop->data << " from the stack." << endl;
     stackTop = stackTop->next;
     delete temp;
   }

   //if list is empty
   else
   {
     cout << "Stack is empty!" << endl;
   }

}

//peek function
void Peek()
{
  //if list has values
  if (stackTop != nullptr)
  {
    cout << "Top element is: " << stackTop->data << endl;
  }

  //if not
  else
  {
    cout << "Stack is empty!" << endl;
  }

}

//display function
void Display()
{
  Node* temp;

  if (stackTop !=nullptr)
  {
    temp = stackTop;
    cout << "Stack elements (top to bottom): ";
      while (temp != nullptr)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
    cout << endl;
  }

  else
  {
    cout << "Stack is empty!" << endl;
  }
}

};

//creates class for queue functions to operate
class Queue
{
  private:
    Node* queueFront;
    Node* queueRear;

  public:
    Queue()
    {
      queueFront = nullptr;
      queueRear = nullptr;
    }

//enqueue function
void Enqueue(int value)
{
  Node* newNode;
  newNode = new Node(value);

  if (queueFront == nullptr)
  {
    queueFront = newNode;
    queueRear = newNode;
  }

  else
  {
    queueRear->next = newNode;
    queueRear = queueRear->next;
  }

  cout << "Enqueued " << value << " into the queue." << endl;
}

//dequeue function
void Dequeue()
{
  Node* temp;

  if (queueFront != nullptr)
  {
    temp = queueFront;
    cout << "Dequeued " << queueFront->data << " from the queue." << endl;
    queueFront = queueFront->next;
    delete temp;
  }

  else
  {
    cout << "Queue is empty!" << endl;
  }
}

//peek function
void Peek()
{
  //if list has values
  if (queueFront != nullptr)
  {
    cout << "Front element is: " << queueFront->data << endl;
  }

  //if not
  else
  {
    cout << "Queue is empty!" << endl;
  }

}

//display function
void Display()
{
  Node* temp;

  if (queueFront !=nullptr)
  {
    temp = queueFront;
    cout << "Queue elements (front to rear): ";
      while (temp != nullptr)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
    cout << endl;
  }

  else
  {
    cout << "Queue is empty!" << endl;
  }
}


};



int main() 
{
  int value;
  int choice;
  Stack stack;
  Queue queue;
  
  while (true)
  {
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
    cout << endl;
    
    switch(choice)
    {
      case 1:
        cout << "Enter value to push: ";
        cin >> value;
        
        stack.Push(value);
        break;
        
      case 2:
        stack.Pop();
        break;
        
      case 3:
        stack.Peek();
        break;
        
      case 4:
        stack.Display();
        break;
        
      case 5:
        cout << "Enter value to enqueue: ";
        cin >> value;
        
        queue.Enqueue(value);
        break;
        
      case 6:
        queue.Dequeue();
        break;
        
      case 7:
        queue.Peek();
        break;
        
      case 8:
        queue.Display();
        break;
        
      case 9:
        cout << "Exiting program..." << endl;
        return 0;

      default:
        cout << "Invalid choice." << endl;

    }
  }
  
  return 0;
  
};
