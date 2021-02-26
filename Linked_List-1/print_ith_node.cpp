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

void print(Node *head)
{
  Node *temp = head;
   while(temp !=NULL)
   {
     cout<<temp->data<<" ";
     temp = temp->next;
   }
}

Node* Input()
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

int length(Node *head)
{
  int length = 0;
  Node *temp = head;
  while(temp!=NULL)
  {
    length++;
    temp = temp->next;
  }
  return length;
}

void print_ith_node(Node *head,int i)
{
  Node *temp = head;
  int c{0};

    while(temp!=NULL)
    {
      if(c == i)
        {
        cout<<"The data of the ith node is : "<<temp->data;
        return;
        }
      else
        {
        temp = temp->next;
        c++;
        }
    }


}

int main()
{
  Node *head = Input();
  cout<<"The LL is as follows : "<<endl;
  print(head);
  cout<<endl<<"The length of the LL is : "<<length(head);
  cout<<endl<<"Enter the index of node required : ";
  int i{0};
  cin>>i;
  print_ith_node(head,i);


  return 0;
}
