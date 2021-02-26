/*
Delete every N nodes

Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list. That is, in the given linked list you need to delete N nodes after every M nodes.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : M

Line 3 : N

Sample Input 1 :
1 2 3 4 5 6 7 8 -1
2
2
Sample Output 1 :
1 2 5 6
Sample Input 2 :
1 2 3 4 5 6 7 8 -1
2
3
Sample Output 2 :
1 2 6 7
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

Node* skipMdeleteN(Node  *head, int M, int N)
{

  Node *temp1 = NULL , *temp2 = NULL;
  temp1 = head;
  int c ;
  while(temp1 != NULL)
    {
      c = 0;
      while(c<M)
        {
          temp1 =temp1->next;
          c++;
        }
        temp2 = temp1;
        c = 0;
        while(c<N && temp2 != NULL)
        {
          temp2 = temp2->next;
          c++;
        }
        temp1->next = temp2->next;
        temp1 = temp1->next;
    }
    return head;
}


int main()
{
    Node* head=Insert();
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}
