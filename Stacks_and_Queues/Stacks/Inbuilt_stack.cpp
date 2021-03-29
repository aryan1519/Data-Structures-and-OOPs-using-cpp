/*
Inbuilt stack also uses templates so we need to specify the type pf data

isEmpty function is a bool function and is named empty

pop function is of type void
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
stack<int> s1;

s1.push(10);
s1.push(20);
s1.push(30);
s1.push(40);
s1.push(50);

cout<<s1.size()<<endl;

cout<<s1.top()<<endl;

s1.pop();

cout<<s1.top()<<endl;

cout<<s1.size()<<endl;

cout<<s1.empty()<<endl;

  return 0;
}
