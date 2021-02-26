// AppendLastNToFirst
// Send Feedback
// Given a linked list and an integer n, append the last n elements of the LL to front.
// Indexing starts from 0. You don't need to print the elements, just update the elements and return the head of updated LL.
// Assume given n will be smaller than length of LL.
// Input format :
//
// Line 1 : Linked list elements (separated by space and terminated by -1)`
//
// Sample Input 1 :
// 1 2 3 4 5 -1
// 3
// Sample Output 1 :
// 3 4 5 1 2

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

int length(Node *head)
{
  if(head == NULL)
    return 0;

  return length(head->next)+1;
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

//Since we need to append the last n nodes we can go to (length - n) th and join the remainging part to the head and change the head.
// important point to note is that we should either first break the LL and join end to beginning first or first find the length then join end to beginning and then break the LL
Node* append_LinkedList(Node* head,int n)
{
  int l = length(head);
  Node *temp = head;

  int count{0};
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = head;

  int c =  l- n;

  Node *temp2  = head;
  while(count<c-1)
  {
    temp2 = temp2->next;
    count++;
  }

  head = temp2->next;
  temp2->next = NULL;
return head;
}

int main()
{

Node *head = Insert();
print(head);

cout<<"\nEnter no of elements : ";
int n{};
cin>>n;

head = append_LinkedList(head,n);

print(head);

return 0;
}
