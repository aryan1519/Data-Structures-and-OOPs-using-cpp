#include<iostream>
#include<unordered_map>

using namespace std;


void PairSum(int *input, int n)
{
    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
      {
        if(m.count(input[i]) == 0)
          m[input[i]] = 1;
        else
          m[input[i]]++;

        if(m.count(-(input[i]))>0)
        {
            for(int c = m[-(input[i])]  ; c>0 ;   c--)
              cout<<min(-(input[i]),input[i])<<" "<<max(-(input[i]),input[i])<<endl;
        }
      }
}



int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);

    return 0;
}
