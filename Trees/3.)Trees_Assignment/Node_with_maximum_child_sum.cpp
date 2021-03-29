/*
Node with maximum child sum

Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Output format :
Node with maximum sum.
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode
{
public:
T data;

vector <TreeNode<T>*> children;

TreeNode(T data)
{
  this->data = data;
}

};

TreeNode<int>* takeInputLevelWise()
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

void print_Level_wise(TreeNode<int>* root)
{
queue <TreeNode<int>*> pendingNodes;
pendingNodes.push(root);

while(pendingNodes.size() != 0)
{
  TreeNode<int>* front;
  front = pendingNodes.front();
  pendingNodes.pop();
  cout<<front->data<<" : ";
  for(int i=0;i<front->children.size();i++)
  {
    if(i!=(front->children.size()-1))
      cout<<front->children[i]->data<<",";
    else
      cout<<front->children[i]->data;

    pendingNodes.push(front->children[i]);
  }
  cout<<endl;
}

}






int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}
