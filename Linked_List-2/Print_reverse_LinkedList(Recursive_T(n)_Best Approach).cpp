/*
After recursion we get 5 4 3 2 Now we need to connect 2 to 1.

We in first approach travel from 5 to 2.

In second approach we make a class to get head and tail head = 5 and tail = 2

Best approach would be to verys simple

even after redcursion 1->next = 2 .

we just make a Node tail = head->next ;
an and then connect tail to head and then change head
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

void print(Node *head)
{
  Node *temp = head;
   while(temp !=NULL)
   {
     cout<<temp->data<<" ";
     temp = temp->next;
   }
}
////////////////////////////////////
Node *reverse(Node *head)
{
  if(head == NULL || head->next == NULL)
    {
      return head;
    }

  Node *smallans = reverse(head->next);

  Node *tail = head->next;

  tail->next = head;
  head->next = NULL;
  head = smallans;

  return head;

}



int main()
{

Node *head = Insert();
print(head);

cout<<"The final linked list is : "<<endl;

Node *h = reverse(head);
print(h);
return 0;
}
