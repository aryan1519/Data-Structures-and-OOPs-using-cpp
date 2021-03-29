#include <iostream>
#include "1.)BinaryTreeNode.h"

using namespace std;

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

//If users enters data as -1 this means there is no data for that node
// This is not a recommended method of taking input as its highly complex for the user.
BinaryTreeNode<int>* takeInput()
{
int rootData{};
cout<<"Enter data "<<endl;
cin>>rootData;

if(rootData == -1)
  return NULL;

BinaryTreeNode<int>* root =  new BinaryTreeNode<int>(rootData);

BinaryTreeNode<int>* leftChild = takeInput();

BinaryTreeNode<int>* rightChild = takeInput();

root->left = leftChild;

root->right = rightChild;

return root;

}

int main()
{
  BinaryTreeNode<int>* root = takeInput();

  printTree(root);
  return 0;
}
