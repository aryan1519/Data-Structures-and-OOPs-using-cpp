#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2)
 {
   unordered_map<int,int> umap;

   for(int i=0;i<size1;i++)
   {
     if(umap.count(input1[i]) == 0)
      umap[input1[i]] = 1;
     else
      umap[input1[i]]++;
   }

   unordered_map<int,int> umap2;

   for(int i=0;i<size2;i++)
   {
     if(umap2.count(input2[i]) == 0)
      umap2[input2[i]] = 1;
     else
      umap2[input2[i]]++;
   }

   unordered_map<int,int>::iterator i;

   for(i = umap.begin();i!=umap.end();i++)
   {
     if(umap2.count(i->first)>0)
      {
        for(int j=0;j<min(i->second,umap2[i->first]);j++)
          cout<<i->first<<endl;
      }
   }


 }


int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];

	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];

	for(int i=0;i<size2;i++)
		cin>>input2[i];


	intersection(input1,input2,size1,size2);


	return 0;
}
