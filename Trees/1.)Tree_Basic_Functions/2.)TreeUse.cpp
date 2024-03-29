#include <iostream>
#include "1.)TreeNode.h"

using namespace std;

void printTree(TreeNode<int>* root)
{
  if(root == NULL)    //not a base case for recursion. Since the function would
  {                   //work without this statement. But if the user does not want any
    return;           //node in the tree then we will get an error without this statement
  }

  cout<<root->data<<" : ";

  for(int i=0;i<root->children.size();i++)
    {
      cout<<root->children[i]->data<<",";
    }
  cout<<endl;

  for(int i =0;i<root->children.size();i++)
  {
    printTree(root->children[i]);
  }
}

int main()
{
TreeNode<int>* root = new TreeNode<int>(1);
TreeNode<int>* node1 = new TreeNode<int>(2);
TreeNode<int>* node2 = new TreeNode<int>(3);

root->children.push_back(node1);
root->children.push_back(node2);
printTree(root);
  return 0;
}
