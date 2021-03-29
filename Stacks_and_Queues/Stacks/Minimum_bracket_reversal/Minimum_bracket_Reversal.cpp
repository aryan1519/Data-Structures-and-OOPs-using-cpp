#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int countBracketReversals(char input[])
{
stack<char> s;
int count{0};
int length = strlen(input);

if(length == 0)
  return 0;

if(length%2 != 0)
  return -1;

int i=0;
  while(i<length)
    {
        if(input[i] == '{')
          s.push('{');

        else
        {
          if(!s.empty() && s.top() == '{')
            s.pop();
          else
            s.push('}');
        }
        i++;
    }

while(!s.empty())
    {
      char c1 = s.top();
      s.pop();
      char c2 = s.top();
      s.pop();
      if(c1 == c2)
        count++;
      else
        count+=2;
      }
      return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}
