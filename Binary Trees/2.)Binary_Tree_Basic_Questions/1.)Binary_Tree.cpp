#include <iostream>
#include <queue>

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

void printBinaryTreeLevelWise(BinaryTreeNode<int>* root)
{
  if(root == NULL)
   	 return ;

    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
      BinaryTreeNode<int>* front = pendingNodes.front();
      pendingNodes.pop();

      cout<<front->data<<":";

        if(front->left != NULL)
        {
            cout<<"L:"<<front->left->data;
            pendingNodes.push(front->left);
        }
        else
        {
            cout<<"L:-1";
        }


        if(front->right != NULL)
        {
            cout<<",R:"<<front->right->data<<endl;
            pendingNodes.push(front->right);
        }
        else
        {
            cout<<",R:-1"<<endl;
        }

    }


}

int main()
{
  BinaryTreeNode<int>* root = takeInputLevelWise();

  printBinaryTreeLevelWise(root);

  delete root;
  return 0;
}
