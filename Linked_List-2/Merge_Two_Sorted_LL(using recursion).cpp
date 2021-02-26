/*
Code: Merge Two Sorted LL
Send Feedback
Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).
Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.
Input format :
Line 1 : Linked list 1 elements of length n (separated by space and terminated by -1)
Line 2 : Linked list 2 elements of length m (separated by space and terminated by -1)
Output format :
Merged list elements (separated by space)
Constraints :
1 <= n, m <= 10^4
Sample Input :
 2 5 8 12 -1
 3 6 9 -1
Sample Output :
 2 3 5 6 8 9 12 
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

Node*head = NULL;
Node*tail = NULL;

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
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

// Node *merge(Node *head1, Node *head2 )
// {
// Node *final_head = NULL;
// Node *curr = NULL;
//
// if(head1->data < head2->data)
// {
//     // final_head = head1;
//     curr = head1;
//     head1 = head1->next;
// }
// else
// {
//   // final_head = head2;
//   curr = head2;
//   head2 = head2->next;
// }
// final_head = curr;
// ////////////////////////////////////
//
// while(head1 != NULL && head2 != NULL)
// {
//   if(head1 <= head2)
//   {
//     curr->next = head1;
//     curr = head1;
//     head1 = head1->next;
//   }
//   else
//   {
//     curr->next = head2;
//     curr = head2;
//     head2 = head2->next;
//   }
// }
//
// if(head1 == NULL)
//   curr->next = head2;
// else
//   curr->next = head1;
//
// return final_head;
// }

Node *merge(Node *head1, Node *head2 )
{
// BASE CASES
if(head1 == NULL)
  return head2;
if(head2 == NULL)
  return head1;

//CALC AND REC CALL

if(head1->data < head2->data)
  {
    head1->next = merge(head1->next,head2);
    return head1;
  }
else
{
  head2->next = merge(head1,head2->next);
  return head2;
}
//////////////
}

int main()
{

  Node *head1= Insert();
  cout<<"\n";
  cout<<"The first LL is : ";
  print(head1);
    cout<<"\n";
  Node *head2 = Insert();
  cout<<"\n";
  cout<<"The second LL is : ";
  print(head2);
  cout<<"\n";

  cout<<"\n The merged LL is : ";
  Node *head3 = merge(head1,head2);
  print(head3);
  return 0;
}
