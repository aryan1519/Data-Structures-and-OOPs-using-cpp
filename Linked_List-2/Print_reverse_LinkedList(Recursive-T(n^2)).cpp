// Print reverse LinkedList
//
// Print a given linked list in reverse order. You need to print the tail first and head last. You can’t change any pointer in the linked list, just print it in reverse order.
// Input format : Linked List elements (separated by space and terminated by -1)
//
// Output format : Linked List elements in reverse order (separated by space)
//
// Sample Input 1 :
// 1 2 3 4 5 -1
// Sample Output 1 :
// 5 4 3 2 1
// Sample Input 2 :
// 1 2 3 -1
// Sample Output 2 :
// 3 2 1



//IMPORTANT
// Even after using recursion the time complexity of this program is T(n^2)
// We can have a better complexity by using double nodes . See the other approach too.
//

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

Node *reverse(Node *head)
{
  if(head == NULL || head->next == NULL)
    {
      return head;
    }

  Node *smallans = reverse(head->next);

  Node *temp = smallans;

  while(temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = head;
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
