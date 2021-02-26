/*
Even after Odd LinkedList

Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
Note: Input and Output has already managed for you. You don't need to print the elements, instead return the head of updated LL.
Input format:
Linked list elements (separated by space and terminated by -1)
Output format:
Print the elements of updated Linked list.
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 5 4 2
Sample Input 2 :
1 11 3 6 8 0 9 -1
Sample Output 2 :
1 11 3 9 6 8 0
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


Node* arrange_LinkedList(Node* head)
{
  Node *odd_head = NULL;
  Node *odd_tail = NULL;
  Node *even_head = NULL;
  Node *even_tail = NULL;

  while(head != NULL)
    {
      if(head->data % 2 != 0 )
        {
          if(odd_head == NULL)
          {
            odd_head = head;
            odd_tail = head;
          }
          else
            {
              odd_tail->next = head;
              odd_tail = odd_tail->next;
            }
        }
      else
        {
            if(even_head == NULL)
            {
              even_head = head;
              even_tail = head;
            }
            else
            {
                even_tail->next = head;
                even_tail = even_tail->next;
            }
        }
        head = head->next;
    }

  // Boundary conditions and return statement
    if(odd_head == NULL)
    {
      return even_head;
    }
    else if(even_head == NULL)
    {
        odd_tail->next = NULL;
        return odd_head;
    }
    else
    {
      odd_tail->next = NULL; // to ensure we have two seperate LL
      even_tail->next = NULL;
      odd_tail->next = even_head;
      return odd_head;
    }
}


int main()
{

Node *head = Insert();
print(head);
cout<<endl;
head = arrange_LinkedList(head);

cout<<endl;

print(head);
  return 0;
}
