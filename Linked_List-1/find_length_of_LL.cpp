#include <iostream>
using namespace std;

class Node
{
public :

  int data;

  Node *next;

  Node(int data)
  {
    this->data =data;
    this->next = NULL;
  }
};
  void print(Node *head)
  {
    Node *temp = head;

    while(temp!= NULL)
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

   while(data !=-1)
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
  Node *temp = head;
  int length{0};
  while(temp!=NULL)
  {
    length+=1;
    temp = temp->next;
  }
  return length;
}




int main()
{
Node *head = Input();

print(head);

cout<<endl<<"The length is : "<<length(head)<<endl;



  return 0;
}
