
#include<iostream>
#include <cstring>
#include <unordered_map>

using namespace std;


char* uniqueChar(char *str)
{
  unordered_map<char,bool> umap;

  int length = strlen(str);

  char *s = new char[length];

  int j=0;
  for(int i=0;i<length;i++)
      {
  		if(umap.count(str[i]) == 0)
          {
              umap[str[i]] = true;
              s[j] =str[i];
              j++;
          }
      }
  s[j] = '\0';
  return s;
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
