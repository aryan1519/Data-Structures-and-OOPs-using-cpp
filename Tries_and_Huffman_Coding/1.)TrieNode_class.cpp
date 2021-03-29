#include <iostream>

using namespace std;

class TrieNode
{
char data;
TrieNode **children;
bool isTerminal;

TrieNode(char data)
{
  this->data = data;
  children = new TrieNode*[26];

  for(int i=0;i<26;i++)
  {
    children[i] = NULL;
  }
  isTerminal = false;
}
};

class Trie
{
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode('\0');
  }

  void InsertHelper(TrieNode *root, string word)
  {
    if(word.size() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'a';
    TrieNode *child;
    if(root->children[index] != NULL)
    {
      child  = root->children[index];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    InsertHelper(child,word.substr(1));
  }

  void InsertWord(string word)
  {
    InsertHelper(root,word);
  }

  bool Search(string word,TrieNode *root)
{
    if(word.size() == 0)
    {
      return root->isTerminal;
    }

    int index = word[0] - 'a';

    TrieNode *child = root->children[index];
    if(child == NULL)
    {
        return false;
    }
    else
        return Search(word.substr(1),child);


}

bool search(string word)
{
    return Search(word,root);
}
};


int main()
{


  return 0;
}
