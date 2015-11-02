#include <stdio.h>
#include <stdlib.h>

typedef struct BNode{
  char value;
  BNode* left;
  BNode* right;
}*BTree;
BNode* built(BNode* tree)
{
   char c;
   printf("%s","please input a char:\n");
   scanf("%c",&c);
   if(c == '#'){
   tree = NULL;
   }
   else
   {
    if(tree == NULL)
        tree=(BNode*)malloc(sizeof(BNode));
    tree->value = c;
    tree->left = built(tree->left);
    tree->right = built(tree->right);
   }
   return tree;
}

int main() {
  	BTree tree = NULL;
        built(tree);
	return 0;
}
