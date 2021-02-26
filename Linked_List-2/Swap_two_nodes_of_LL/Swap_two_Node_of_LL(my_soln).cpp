/*
Swap two Node of LL

Given a linked list, i & k, swap the nodes that are present at i & k position in the LL. You need to swap the entire nodes, not kust the data.
Indexing starts from 0. You don't need to print the elements, kust swap and return the head of updated LL.
Assume i & k given will be within limits. And i can be greater than k also.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : i and k (separated by space)

Sample Input 1 :
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9
Sample Input 2 :
3 4 5 2 6 1 9 -1
2 4
Sample Output 2 :
3 4 6 2 5 1 9
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

int main()
{
    Node* head=Insert();
    print(head);
    cout<<endl;
    int i,j;
    cin>>i >> j;
    cout<<endl;
    head= swap_nodes(head,i,j);
    print(head);
    return 0;
}
