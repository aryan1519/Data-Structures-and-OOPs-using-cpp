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

int countLeafNodes(TreeNode<int>* root)
{
int ans{};
if (root == NULL)
  return 0;

if (root->children.size() == 0)
  return 1;

for(int i=0;i<root->children.size();i++)
{
  ans+=countLeafNodes(root->children[i]);
}
return ans;
}

int main()
{
  TreeNode<int> *root = InputLevelWise();
  printLevelWise(root);

  int no_of_leaf_nodes = countLeafNodes(root);
  return 0;
}
