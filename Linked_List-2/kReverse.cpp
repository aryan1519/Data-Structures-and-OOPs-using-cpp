/*
kReverse

Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.
Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.
You don't need to print the elements, just return the head of updated LL.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : k

Sample Input 1 :
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
1 2 3 4 5 -1
2
Sample Output 2 :
2 1 4 3 5
Sample Input 3 :
1 2 3 4 5 6 7 -1
3
Sample Output 3 :
3 2 1 6 5 4 7

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

Node *reverse(Node *head)
{
  if(head == NULL || head->next == NULL)
  return head;


  Node *temp1 = reverse(head->next);

  head->next->next = head;

  head->next = NULL;

 head = temp1;

  return head;
}

int length(Node *head)
{
  if(head == NULL)
    return 0;

  return length(head->next)+1;
}

Node *krev(Node *head ,int k)
{
  if(head == NULL || head->next == NULL)
    return head;

  if (k>length(head))
    return reverse(head);

  int c = 0;
  Node *temp1 = head;
  Node *temp2 = head;
  while(c<k-1)
    {
      temp2=temp2->next;
      c++;
    }
    Node *temp3 = temp2->next;
    temp2->next = NULL;

    Node *head1 = reverse(temp1);

    Node *head2 = krev(temp3,k);

    temp1->next = head2;

    head = temp2;
    return head;
}

int main()
{

Node *head = Insert();
print(head);

cout<<endl;

int k {};
cin>>k;

cout<<endl;
Node * head2 = krev(head,k);
cout<<endl;
print(head2);

  return 0;
}
