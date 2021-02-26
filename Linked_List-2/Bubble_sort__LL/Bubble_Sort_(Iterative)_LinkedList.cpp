/*
Bubble Sort (Iterative) LinkedList

Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
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

Node *swap_nodes(Node *head, int i ,int j)
{
  Node *temp1 = head;
  Node *temp2;
  Node *temp3;
  Node *temp4;
  Node *temp5;
    int c = 0;

  int k=j;
  if(i>j)
  {
    k=i;
    i=j;
  }


    if(i == 0 && k!=1)
    {
      temp2 = head;
      temp3= temp2->next;
      while(temp1->next != NULL)
      {
        if(c == k-1)
        {
          temp4 = temp1;
          temp5 = temp4->next; //tbs
        }
        temp1 = temp1->next;
        c++;
      }
      temp4->next = temp2;
      temp2->next = temp5->next;
      temp5->next = temp3;
      head = temp5;
    }

    else if(i == 0 && k == 1)
    {
      temp2 = temp1->next;
      temp3 =temp2->next;
      temp2->next = temp1;
      temp1->next =temp3;
      head= temp2;

    }
  else
  {
    while(temp1->next != NULL)
    {
      if(c == i-1)
      {
        temp2 = temp1;
        temp3 = temp2->next; //tbs

      }
      if(c == k-1)
      {
        temp4 = temp1;
        temp5 = temp4->next; //tbs
      }
      temp1 = temp1->next;
      c++;
    }

    temp2->next = temp5;
    Node *temp = temp5->next;

    temp4->next = temp3;

    temp5->next = temp3->next;

    temp3->next = temp;
  }
    return head;
}

int length(Node *head)
{
  if(head == NULL)
    return 0;

  return length(head->next)+1;
}

Node *bubble_sort_LinkedList_itr(Node *head)
{
  int i{} ;
  int j =0;
Node *temp1 ;
Node *temp2 ;
Node *temp3;
Node *temp4;
  for(i = length(head)-1;i>0;i--)
  {
    for(j = 0;j<i;j++)
    {
      temp1 = head;
      temp2 = temp1->next;

      if(temp1->data > temp2->data)
      {
        temp4 = temp1
        temp3 = temp2->next;
        temp2->next = temp1;
        temp1->next = temp3;
      }
    }
  }
}

int main()
{

Node *head = Insert();
print(head);



  return 0;
}
