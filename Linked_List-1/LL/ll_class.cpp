#include <iostream>
using namespace std;

class Node
{
public:
  int data;

  //pointer to store the address of next node.Thus of type node
  Node *next;

  //constructor to always get input of dataand initialize next to NULL
  //So now whenever we create a node we take input of data and this node points to NULL
  Node(int data)
  {
    this->data = data;
    next = NULL;
  }

  //Creating the print function
  // Read notes for details
  void print(Node *head)
  {
  Node *temp = head;

    while(temp != NULL)
    {
    cout<<temp->data<<" ";
    temp = temp->next;
    }
  }

  // creating the take input FUNCTION
  // Read notes for details

  Node* takeInput()
  {
    int data;
    cin>>data;

    Node *head = NULL;
    Node *tail = NULL;

    while(data!= -1)
    {
      Node *newNode = new Node(data);

      if(head == NULL)
      {
        head = newNode;
        tail = newNode;
      }

      else
      {
        tail->next = newNode;
        tail = newNode;
      }
      cin>>data;
    }

    return head;
  }

};
