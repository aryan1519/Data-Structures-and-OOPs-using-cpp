#include <iostream>
#include "2.)Implementation_of_umap_using_hashtables.cpp"

using namespace std;

int main()
{
Map<int> map;

// for(int i =0;i<10;i++)
// {
//   char c = '0'+i;
//   string key = "abc";
//   key = key + c;
//
//   int value = i+1;
//
//   map.insert(key,value);
//
//   cout<<map.getLoadFactor()<<endl<<endl;
// }

for(int i=0;i<10;i++)
{
  char c = '0'+i;
  string key = "abc";
  key = key+c;
  cout<<key<<" : "<<map.getValue(key)<<endl;
}
cout<<map.size()<<endl;

return 0;
}
