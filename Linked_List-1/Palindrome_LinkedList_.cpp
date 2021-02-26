// Palindrome LinkedList
//
// Check if a given linked list is palindrome or not. Return true or false.
// Indexing starts from 0.
// Input format : Linked list elements (separated by space and terminated by -1)
//
// Sample Input 1 :
// 9 2 3 3 2 9 -1
// Sample Output 1 :
// true
// Sample Input 2 :
// 0 2 3 2 5 -1
// Sample Output 2 :
// false

////////////////////////////////////////////////
/*
IMPORTANT
Ways of solving
1.)Iterative method
    T(n^2)
    S(1)
2.) For the given LL form a new LL reverse of the first and now compare each element
    T(n)
    S(n) // not good

  3.)Best Approach
     Since in a pallindrome LL the second half is symmetric to first half
     what we can do is just reverse the second half and compare element by element to firdt half
     We need to take care of even and odd elements LL .
*/
/////////////////////////////////////

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

Node* rev(Node *head)
{
  if(head == NULL || head->next == NULL)
    return head;

  Node *smallans = rev(head->next);

  head->next->next = head;
  head->next = NULL;

  return smallans;
}

Node* mid(Node *head)
{
Node *slow = head;
Node *fast = head;
while(fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

bool check_palindrome(Node* head)
{
  Node *mid_head = mid(head);

  mid_head = rev(mid_head);

  while(mid_head != NULL)
  {
    if(head->data != mid_head->data)        // Make sure were comparing the data and not the pointers
      {
        return false;
      }
    else
      {
        head = head->next;
        mid_head = mid_head->next;
      }
  }
  return true;
}


int main()
{
    Node* head=Insert();
    cout<<endl;
    print(head);

    cout<<endl;
cout<<check_palindrome(head);

    return 0;
}
