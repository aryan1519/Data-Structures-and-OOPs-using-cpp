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

///////////////////////////////////////////

Node* Insert_at_i_recursive(Node *head,int i, int data)
{

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
head = Insert_at_i_recursive(head,i,data);
print(head);

  return 0;
}
