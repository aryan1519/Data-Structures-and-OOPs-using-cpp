/*
Contains x

Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
Input format :
Line 1 : Integer x
Line 2 : Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Output format :
true or false
Sample Input 1 :
40
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Sample Input 2 :
4
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 2:
false
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


bool containsX(TreeNode<int>* root, int x)
 {
   bool ans = true;

   if(root == NULL)
    return false;

   if(root->data == x)
    return true;

  for(int i=0;i<root->children.size();i++)
  {
    ans =  containsX(root->children[i],x);
  }

return ans;
}



int main() {
    int x;
    cin >> x;
    TreeNode<int>* root = takeInputLevelWise();
    if(containsX(root, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
