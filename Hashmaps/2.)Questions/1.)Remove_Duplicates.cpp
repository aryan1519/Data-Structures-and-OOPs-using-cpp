#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> remove(int* arr,int n)
{
  vector<int> output;

  unordered_map<int,bool> seen;

  for(int i=0;i<n;i++)
  {
    if(seen.count(arr[i]) != 0)
      continue;
    else
      seen[arr[i]] = true;
      output.push_back(arr[i]);
  }

  return output;
}

int main()
{
  int n{};
  cout<<"Enter the size of the array : ";
  cin>>n;
  int arr[n];
  cout<<"\nEnter the elements of the array :-"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  cout<<"\n\nThe array elements before removing duplicates are:-"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }

  vector<int> output = remove(arr,n);

  cout<<"\n\nThe array elements after removing duplicates are:-"<<endl;

  for(int i=0;i<output.size();i++)
  {
    cout<<output[i]<<" ";
  }

  return 0;
}
