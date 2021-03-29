#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
  T data;

  vector <TreeNode<T>*> children ;

  TreeNode(T data)
  {
    this->data = data;
  }
};

void printTree(TreeNode<int> *root)
{
if(root == NULL)
  return;

  cout<<root->data<<" : ";

  for(int i=0;i<root->children.size();i++)
  {
    cout<<root->children[i]->data<<",";
  }
  cout<<endl;

  for(int i=0;i<root->children.size();i++)
  {
    printTree(root->children[i]);
  }
}

TreeNode<int>* takeInputLevelwise()
{
  int rootData{};
  cout<<"Enter root data"<<endl;
  cin>>rootData;

  TreeNode<int>* root = new TreeNode<int>(rootData);

  queue<TreeNode<int>*> pendingNodes ;
  pendingNodes.push(root);

  while(pendingNodes.size() != 0)
  {
    TreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();

    cout<<"Enter the number of children of "<<front->data<<endl;
    int n{};
    cin>>n;

    for(int i=0;i<n;i++)
    {
      int child_data{};
      cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
      cin>>child_data;

      TreeNode<int>* child = new TreeNode<int>(child_data);

      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
return root;
}

int main()
{
TreeNode<int> *root = takeInputLevelwise();

printTree(root);

return 0;
}
