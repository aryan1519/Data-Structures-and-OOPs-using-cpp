// unordered map is implemented using hash tables
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  //Creating an unodered_map
  unordered_map<string,int> umap;

  //Insert

    //Method - 1
    pair<string,int> p("abc",1);
    umap.insert(p);

    //Method - 2
    umap["def"] = 2;

  //Accessing values
    //Method - 1
    cout<<umap["abc"]<<endl;

    //Method - 2
    cout<<umap.at("def")<<endl;

    //There is a major difference between umap[] and umap.at()
    //If a key doesnt exist in the map and we use .at() they we will get an error

    //If a key doesnt exist in the map, umap[] would create a key and give it a default
    //value of 0.This is not needed sometimes as it unncessearily adds a key to the map.

    //We must thus use the two functions appropriately.

    //Checking presence of a key
    //One way to ensure using the two functions would be using the count function.
    //A map can have only distinct keys so the count of a key can either be 1 or 0.

    if(umap.count("ghi") != 0)
      cout<<umap.at("ghi")<<endl;
    else
      cout<<"The key - ghi is not in the map."<<endl;

    cout<<"ghi - "<<umap["ghi"]<<endl;
    cout<<"count of key ghi now - "<<umap.count("ghi")<<endl;

    //Erasing a key
      umap.erase("ghi");
      cout<<"count of key ghi after erasing - "<<umap.count("ghi")<<endl;


  return 0;
}
