/*
Code: Midpoint of LL

Given a linked list, find and return the midpoint.
If the length of linked list is even, return the first mid point.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 2 3 4 5 -1
Sample Output 1 :
3
Sample Input 2 :
1 2 3 4 -1
Sample Output 2 :
2
*/

#include <iostream>

using namespace std;

class Node
{
public:
int data;
Node *next;

Node(int data)
  {
    this->data = data;

    this->next = NULL;
  }
};


Node* Insert()
{
int data;
cin>>data;

Node*head = NULL;
Node*tail = NULL;

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

void print(Node *head)
{
  Node *temp = head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

//without using the length function
int midpoint(Node *head)
{
Node *slow =head;
Node *fast = head->next;

while(fast!= NULL && fast->next != NULL)
{
  slow =slow->next;
  fast = fast->next->next;
}
return slow->data;
}
int main()
{

  Node *head= Insert();

  print(head);
  cout<<"\n The midpoint data is : "<<midpoint(head);
  return 0;
}
