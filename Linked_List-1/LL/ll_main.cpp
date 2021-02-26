// This is a program to take LL as input and then print it

#include <iostream>
using namespace std;
#include "ll_class.cpp"

int main()
{
Node *head = head->takeInput();       //Here we have to write head->takeInput() as takeInput is a function of the class Node.
                                      // we can make the functions outside the class and then directly call takeInput()

  head->print(head);
}
