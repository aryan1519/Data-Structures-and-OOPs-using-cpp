#include<iostream>
#include <unordered_map>

using namespace std;

int highestFrequency(int *input, int n)
{
    unordered_map<int,int> umap;

    pair<int,int> max = {0,0};

    for(int i=0;i<n;i++)
    {
      if(umap.count(input[i]) ==0)
        {
          umap[input[i]] = 1;
          if(umap[input[i]]>max.second)
            {
              max.first = input[i];
              max.second = umap[input[i]];
            }
        }
      else
      {
        umap[input[i]]++;
        if(umap[input[i]]>max.second)
          {
            max.first = input[i];
            max.second = umap[input[i]];
          }
      }
    }

    return max.first;

}



int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}
