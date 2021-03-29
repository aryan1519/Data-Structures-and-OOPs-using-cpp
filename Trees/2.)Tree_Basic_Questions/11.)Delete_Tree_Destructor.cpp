#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//changes made in the TreeNode class , destructor added.
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

    ~TreeNode()
    {
      for(int i=0;i<children.size();i++)
      {
        delete children[i];
      }
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

int main()
{
  TreeNode<int> *root = InputLevelWise();

printLevelWise(root);

delete root;

printLevelWise(root); // Since tree noloner exists we will get garbage value.

  return 0;
}
