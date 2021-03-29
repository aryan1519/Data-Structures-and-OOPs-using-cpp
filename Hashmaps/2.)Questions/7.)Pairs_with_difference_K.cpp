#include<iostream>
#include<unordered_map>
using namespace std;


void printPairs(int *input, int n, int k) {
	// Write your code here
  unordered_map<int,int> m;

  for(int i=0;i<n;i++)
  {
	m[input[i]]++;
  }

	for(int i=0;i<n;i++)
    {
        int key = input[i];

        if(k == 0)
        {
            int a = m[key];
            int count = ((a-1)*a)/2;

            for(int j=0;j<count;j++)
                cout<<key<<" "<<key<<endl;
        }
        else
        {
            int b= input[i]+k;
            int f = input[i]-k;

            int count = m[key];
            int bcount = m[b];
            int fcount = m[f];

            for(int j=0;j<count*bcount;j++)
                cout<<min(b,key)<<" "<<max(b,key)<<endl;
            for(int j=0;j<count*fcount;j++)
                cout<<min(f,key)<<" "<<max(f,key)<<endl;
        }
        m.erase(key);

    }

}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
