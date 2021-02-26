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
///////////////////////////////////////////

void print(Node *head)
{
  Node *temp = head;

  while(temp != NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}
////////////////////////////////////////////

Node *Input()
{

int data;
cin>>data;

Node *head = NULL;
Node *tail = NULL;

while(data != -1)

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
//////////////////////////////////////////

int FindLength(Node *head)
{
  int length = 0;
  Node *temp = head;
  while(temp != NULL)
  {
    length++;
    temp = temp->next;
  }
  return length;
}


///////////////////////////////////////////

Node* Insert_at_i(Node *head,int i, int data)
{
  Node *newNode = new Node(data);

  int count = 0 ;

  Node *temp = head;

  if(i == 0 )
  {
  newNode->next = head;
  head = newNode;
  return head;
  }
  while(temp !=NULL && count<i-1)
    {
    temp = temp->next;
    count++;
    }

    if(temp!= NULL)
    {
    newNode->next = temp->next;
    temp->next = newNode;
    }
    return head;

}

int main()
{
Node *head = Input();
print(head);

cout<<"\nEnter the index where you want to insert the element : ";
int i{};
cin>>i;
cout<<"Enter data : ";
int data;
cin>>data;
head = Insert_at_i(head,i,data);
print(head);

  return 0;
}
