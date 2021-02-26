/*
Eg 1 2 3 4 5 NULL
In the regular approach using recursion we fist assume we get 5 4 3 2  with recursion and we travel from 5 to 2 and connect 2 to 1 and make 5 the head.

This approach has a time compexity of n^2.

The loop used to travel from 5 to 2 is unncesseary and can be avoided by using two nodes.

Two node strategy


We make two nodes head and tail and expect recursion to give both head and tail head being 5 and tail being 2

Now this involves returning two variables which isnt possible with the return statement.

We can return an object that has two members head and tail.

Thus we make a class , lets say named Pair.

Now we will have to make a new reverse function od return type pair.

Since we are given the function reverse of type Node we will have that too and this will get result from our Pair type reverse fucntion
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

class Pair
{

  public :

  Node *head;
  Node *tail;
};

Pair rev(Node *head)
{

  if(head == NULL || head->next == NULL)
  {
    Pair ans;
    ans.head = head;
    ans.tail = head;
    return ans;
  }

  Pair smallans = rev(head->next);

  smallans.tail->next = head;
  head->next = NULL;

  Pair ans;
  ans.head = smallans.head;
  ans.tail = head;
  return ans;
}
Node *reverse(Node *head)
{
return rev(head).head;
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
