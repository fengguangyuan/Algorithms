#include <iostream>
using namespace std;

struct Node{
  int value;
  Node* parent;
  Node* right;
  Node* left;
}BNode,*pBNode;
struct BTree{
  int value;
  pBNode head;
};
pBNode built(pBNode child)
{
    if(child->value == 0)
	  return NULL;
	BNode *node = (BNode*)malloc(sizeof BNode);
	node->value = 0;
    node->left = node->right = NULL;
    cout<<"请输入左子结点的值："<<endl;
    cin>>node->value;
    child->left = built(child->left);
	BNode *node2 = (BNode*)malloc(sizeof BNode);
	node2->value = 1;
	node2->left = node2->right = NULL;
    cout<<"请输入右子节点的值："<<endl;
    cin>>node2->value;
    child->right = built(child->right);
  	return node;
}
void bitree(BTree* tree){
  if(NULL == tree->head)
  {
	tree->head = (pBNode)malloc(sizeof BNode);
	tree->head->value = 1;
	tree->head->left=tree->head->right=NULL;
  }else{
	built(tree->head);
  }
}

int main() {
	cout<<"Hello"<<endl;
    cout<<"start building"<<endl;
    BTree tr;
    tr.value=-1;
    bitree(&tr);
	return 0;
  
}



