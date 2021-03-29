#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{

unordered_map<int,bool> m;


    for(int i=0;i<n;i++)
    {
       m[arr[i]] = true;;
    }

    unordered_map<int,bool>::iterator i;

    int start = 0;
    int count = 0 ;
    pair<int,int> max;
    for(i = m.begin();i!=m.end();i++)
    {
        count = 0;
        if(i->second != false)
        {
            m[start] = false;
            start = i->first;
            int temp = start+1;
                while(true)
                {
                    if(m[temp])
                    {
                        count++;
                        temp++;
                        m[temp] = false;
                    }
                    else
                        break;
                }
                temp = start-1;
                while(true)
                {
                    if(m[temp])
                    {
                        count++;
                        start--;
                        temp--;
                        m[temp] = false;
                    }
										else
											break;
                }
        }
        if(count>max.second)
        {
            max.first = start;
            max.second = count;
        }

    }

    vector<int>output;
    int j = max.first;
    for(int i=0;i<max.second;i++)
    {
        output.push_back(j);
        j++;
    }

    return output;
}


int main(){
  int size;

  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);

  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}
