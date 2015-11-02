#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
typedef struct BNode{
  char value;
  BNode* left;
  BNode* right;
}*BTree;
//create a new binary tree
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

//pre-order to show the tree
void preorder(BTree tree)
{
    if(tree)
    {
        printf("%c,",tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }else{
        return;
    }
}
//show the tree by levels traveling
void showWithQueue(BTree tree)
{
    printf("%s\n","show the tree with a stack by levels traveling:");
    if(tree == NULL)
        return;
    else{
        std::queue<BNode*> q;
        q.push(tree);
        while(!q.empty()&&q.front()!=NULL)
        {
            BNode* tmp = q.front();
            q.pop();
            printf("%c\n",tmp->value);
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right);
                q.push(tmp->right);
        }
       printf("%s\n","**** end ****");
    }
}
void showWithStackByMidorder(BTree tree)
{
    printf("%s\n","show the tree with a stack by pre-order:");
    if(tree==NULL)
        return;
    else{
        std::stack<BNode*> st;
        st.push(tree);
        BNode* tmp = st.top();
        while(!st.empty() || tmp)
        {
            while(tmp)
            {
                if(tmp->left)
                   st.push(tmp->left);
                tmp = tmp->left;
            }
            tmp = st.top();
            printf("%c\n",tmp->value);
            st.pop();
            if(tmp->right)
                st.push(tmp->right);
            tmp=tmp->right;
        }
        printf("%s\n","******* end ******");
    }
}
void showWithStackByPreorder(BTree tree)
{
    printf("%s\n","show the tree with a stack by mid-order:");
    if(tree==NULL)
        return;
    else{
        std::stack<BNode*> st;
        BNode* tmp = tree;
        while(!st.empty() || tmp)
        {

            while(tmp)
            {
                st.push(tmp);
                printf("%c\n",tmp->value);
                tmp = tmp->left;
            }
            tmp = st.top();
            st.pop();
            tmp = tmp->right;
        }
        printf("%s\n","******* end ******");
    }
}
//the depth of the tree
int depth(BTree tree)
{
    if(tree == NULL)
        return 0;
    int left = depth(tree->left)+1;
    int right = depth(tree->right)+1;
    return left>right?left:right;
}
int depth2(BTree tree)
{
    if(tree == NULL)
        return 0;
    else{
        int l = depth2(tree->left);
        int r = depth2(tree->right);
        return (l>=r)?(l+1):(r+1);
    }
}
//the number of the  leaves of this tree
int leaves(BTree tree){
    int count = 0;
    if(tree == NULL)
        return 0;
    else{
        if(tree->left==NULL&&tree->right==NULL)
            ++count;
        count += leaves(tree->left)+leaves(tree->right);
    }
    return count;
}
int main() {
  	BTree tree = NULL;
  	tree = (BNode*)malloc(sizeof(BNode));
  	tree->left = (BNode*)malloc(sizeof(BNode));
  	tree->left->value = 'a';
  	tree->left->left = tree->left->right = NULL;
  	tree->right = NULL;
  	tree->value = '@';
  	BNode* tl = tree->left;
  	tl->right = (BNode*)malloc(sizeof(BNode));
  	tl->right->value = 'c';
  	tl->right->left = tl->right->right = NULL;
  	tree->right = (BNode*)malloc(sizeof(BNode));
  	tree->right->value = 'd';
  	tree->right->left = tree->right->right = NULL;
  	preorder(tree);
  	printf("%d\n",depth(tree));
  	printf("%d\n",depth2(tree));
  	printf("%d\n",leaves(tree));
  	showWithQueue(tree);
  	showWithStackByPreorder(tree);
  	showWithStackByMidorder(tree);
	return 0;
}
