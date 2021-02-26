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

Node* delete_at_i(Node *head,int i)
{
  Node *temp = head;
  if(i == 0)
  {
    head = head->next;
    delete temp;
    return head;
  }
  int count = 0 ;
  while(temp!=NULL && count<i-1)
  {
    temp = temp->next;
    count++;
  }
  if(temp->next!=NULL)          //Import checkpoint
  {
    Node *a = temp->next;
    temp->next = temp->next->next;
    delete a;
  }
  return head;
}

int main()
{
Node *head = Input();
print(head);

cout<<"\nEnter the index of the element you want to delete : ";
int i{};
cin>>i;
head = delete_at_i(head,i);
print(head);

  return 0;
}
