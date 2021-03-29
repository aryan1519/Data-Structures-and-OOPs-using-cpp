#include <iostream>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  ~BinaryTreeNode()
  {
    delete left;
    delete right;
  }
};

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


BinaryTreeNode<int>* takeInputLevelWise()
{

int rootData{};
cout<<"Enter root data "<<endl;
cin>>rootData;

if(rootData == -1)
  return NULL;

BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

queue<BinaryTreeNode<int>*> pendingNodes;

pendingNodes.push(root);

while(pendingNodes.size()!= 0)
{

BinaryTreeNode<int>* front = pendingNodes.front();
pendingNodes.pop();

int leftData{};
cout<<"Enter left child of "<<front->data<<endl;
cin>>leftData;

int rightData{};
cout<<"Enter right child of "<<front->data<<endl;
cin>>rightData;

if(leftData !=-1)
{
  BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
  pendingNodes.push(leftChild);
  front->left = leftChild;
}

if(rightData !=-1)
{
BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
pendingNodes.push(rightChild);
front->right = rightChild;
}

}
return root;
}
/////////////////////////////////////////////////

int maximum(BinaryTreeNode<int>* root)
{
  if(root == NULL)
    return INT_MIN;

  return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root)
{
  if(root == NULL)
    return INT_MAX;

  return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool checkBST(BinaryTreeNode<int>* root)
{
  if(root == NULL)
    return true;

  int lmax = maximum(root->left);
  int rmin = minimum(root->right);

bool output = (root->data > lmax) && (root->data < rmin) && (checkBST(root->left)) && (checkBST(root->right));
return output;
}

int main()
{
  BinaryTreeNode<int>* root = takeInputLevelWise();
  cout<<checkBST(root);

  return 0;
}
