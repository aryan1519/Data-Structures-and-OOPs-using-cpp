#include <vector>

using namespace std;

/*
A tree node will have a data elements and it will store the addresses of all its childeren

so we will use  a vector of pointers which will store all the address of chidlren of a node.
*/


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
