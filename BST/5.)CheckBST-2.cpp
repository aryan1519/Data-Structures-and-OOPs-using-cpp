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
class Triplet
{
public:
  bool isBST;
  int minimum;
  int maximum;
};

Triplet checkBST(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
      Triplet output;
      output.isBST = true;
      output.minimum = INT_MAX;
      output.maximum = INT_MIN;
      return output;
    }

    Triplet leftoutput = checkBST(root->left);
    Triplet rightoutput = checkBST(root->right);

    int overall_minimum = min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    int overall_maximum = max(root->data,max(leftoutput.maximum,rightoutput.maximum));

    bool overall_isBst = (root->data>leftoutput.maximum) && (root->data<rightoutput.minimum) && (leftoutput.isBST) && (rightoutput.isBST);

    Triplet overall_output;
    overall_output.minimum = overall_minimum;
    overall_output.maximum = overall_maximum;
    overall_output.isBST = overall_isBst;

    return overall_output;

}


int main()
{
  BinaryTreeNode<int>* root = takeInputLevelWise();
  Triplet ans = checkBST(root);
  cout<<ans.isBST<<endl;
  return 0;
}
