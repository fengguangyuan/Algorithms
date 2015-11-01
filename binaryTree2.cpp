#include <iostream>
using namespace std;

struct BNode{
  int value;
  BNode* left;
  BNode* right;
}*BTree;

void built(BTree tree)
{
  if(tree == NULL)
  {
	tree = (BNode*)malloc(sizeof BNode);
	tree->left = tree->right = NULL;
	cout<<"Please input a value:"<<endl;
	cin>>tree->value;
	if(tree->value == 0);
		return;
  }
  built(tree->left);
  built(tree->right);
}

int main() {
	cout<<"Hello"<<endl;
  	BTree tree = NULL;
    built(tree);
	return 0;
}
