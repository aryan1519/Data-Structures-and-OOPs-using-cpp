#include <iostream>
#include <stack>
#include <cstring>

using namespace std;


bool checkBalanced(char *exp)
{
int length = strlen(exp);
stack<char> par;
  for(int i=0;i<length;i++)
    {
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
          par.push(exp[i]);

        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
          if(par.empty())
            return false;

            char a = par.top();
            par.pop();


          if(exp[i] == ')' && a == '(')
          	continue;
          else if(exp[i] == '}' && a == '{')
         	 continue;
          else if(exp[i] == ']' && a == '[')
         	 continue;
          else
         	 return false;
        }

    }
    return par.empty();
}

int main()
{
  char input[100000];
  cin.getline(input, 100000);
   cin >> input;
  if(checkBalanced(input)) {
      cout << "true" << endl;
  }
  else {
      cout << "false" << endl;
  }


  return 0;
}
