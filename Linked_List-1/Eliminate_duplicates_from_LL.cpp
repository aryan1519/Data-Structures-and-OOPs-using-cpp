// Eliminate duplicates from LL
// Send Feedback
// Given a sorted linked list (elements are sorted in ascending order). Eliminate duplicates from the given LL, such that output LL contains only unique elements.
// You don't need to print the elements, just remove duplicates and return the head of updated LL.
// Input format : Linked list elements (separated by space and terminated by -1)
//
// Sample Input 1 :
// 1 2 3 3 3 4 4 5 5 5 7 -1
// Sample Output 1 :
// 1 2 3 4 5 7


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

Node *delete_duplicate(Node *head )
{
  Node *temp1 = head;
  Node *temp2 = head->next;

  if(head == NULL || head->next == NULL )                                       //NOTE: make changes in this prgram to deallocate space of the removed node too.
    return head;

  while(temp2 != NULL)
  {
    if(temp1->data != temp2->data)
    {
      temp1 = temp2;
      temp2 = temp2->next;
    }
    else
    {
      temp2 = temp2->next;
    }
  temp1->next = temp2;

  }

  return head;
}


int main()
{

Node *head = Insert();
print(head);

cout<<"The final linked list is : "<<endl;

Node *h = delete_duplicate(head);
print(h);
return 0;
}
