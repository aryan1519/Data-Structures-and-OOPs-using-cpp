#include <iostream>
#include "1.)BinaryTreeNode.h"

using namespace std;

//Basic function just to check BinaryTreeUse
void printTree(BinaryTreeNode<int>* root)
{
  if(root == NULL) //Necessary
    return;

  cout<<root->data<<" : ";
  if(root->left!= NULL)
    cout<<"L"<<root->left->data<<" ";
  if(root->right!= NULL)
    cout<<"R"<<root->right->data<<" ";

  cout<<endl;

  printTree(root->left);
  printTree(root->right);
}

int main()
{
BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

root->left = node1;
root->right = node2;

printTree(root);

delete root;
}
