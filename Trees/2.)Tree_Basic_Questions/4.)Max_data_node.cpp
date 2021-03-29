/*
Code : Max data node

Given a generic tree, find and return the node with maximum data. You need to return the complete node which is having maximum data.
Return null if tree is empty.
Input format :
Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Output Format :
Node with largest data
Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output :
50
*/


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
  public:
    T data;

    vector<TreeNode<T>*> children;

    TreeNode(T data)
    {
      this->data = data;
    }

};

TreeNode<int>* InputLevelWise()
{
  int rootData{};
  cout<<"Enter root data "<<endl;
  cin>>rootData;

  TreeNode<int>* root = new TreeNode<int>(rootData);

  queue<TreeNode<int>*> pendingNodes;

  pendingNodes.push(root);

  while(pendingNodes.size()!=0)
  {
    TreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();

    int n{};
    cout<<"Enter the number of children of "<<front->data<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
      int c_data;
      cout<<"Enter the "<<i<<"th child of "<<front->data<<endl;

      cin>>c_data;

      TreeNode<int>* child = new TreeNode<int>(c_data);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

void printLevelWise(TreeNode<int>* root)
{
queue<TreeNode<int>*> pendingNodes ;

pendingNodes.push(root);

while(pendingNodes.size()!=0)
{
TreeNode<int>* front = pendingNodes.front();
pendingNodes.pop();

cout<<front->data<<" : ";

for(int i =0;i<front->children.size();i++)
{
  if(i!= front->children.size()-1)
    cout<<front->children[i]->data<<",";
  else
    cout<<front->children[i]->data;

  pendingNodes.push(front->children[i]);
}
cout<<endl;
}
}



TreeNode<int>* maxDataNode(TreeNode<int>* root)
 {
   TreeNode<int>* max = root;

    if(root == NULL)
        return NULL;

   if(root->data >max->data)
      max = root;

      for(int i=0;i<root->children.size();i++)
      {
        TreeNode<int>* temp = maxDataNode(root->children[i]);

        if(temp->data > max->data)
          max = temp;

      }

return max;

 }


int main()
{
  TreeNode<int> *root = InputLevelWise();
  printLevelWise(root);

  TreeNode<int>* max = maxDataNode(root);
  cout<<"Max = "<<max->data<<endl;
  return 0;
}
