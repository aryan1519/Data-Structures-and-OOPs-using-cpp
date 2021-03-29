#include <iostream>
#include <queue>

using namespace std;

int main()
{

  queue<int> q1;

  q1.push(10);
  q1.push(20);
  q1.push(30);
  q1.push(40);
  q1.push(50);
  q1.push(60);

  cout<<q1.front()<<endl;

  q1.pop();

  cout<<q1.front()<<endl;

  cout<<q1.empty()<<endl;

  cout<<q1.size()<<endl;

  return 0;
}
