#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct A {
    int multi;
    int value;
    int no;
    int start;
    int end;
    A* left;
    A* right;
} Tree;

// N % 2 == 0
void buildTree(Tree* tr, int node, int l, int r) {
    cout << "creating node " << node << endl;
    cout << "<L, R> = <" << l <<", " << r << endl;
    if (l == r) {
        tr[node].multi = 0;
        tr[node].value = 0;
        tr[node].no = node;
        tr[node].start = l;
        tr[node].end = r;
        tr[node].left = tr[node].right = nullptr;
        return;
    } else {
    }
    // build left sub tree
    buildTree(tr, node << 1, l, (l + r) >> 1);
    // build right sub tree
    buildTree(tr, 2 * node + 1, ((l + r) >> 1) + 1, r);
    // In backtracing, calculate the muti value Ai *...* Aj
    tr[node].left = &(tr[node * 2]);
    tr[node].right = &(tr[node * 2 + 1]);
    tr[node].no = node;
    tr[node].start = l;
    tr[node].end = r;
    tr[node].value = tr[node / 2].value * tr[node / 2 + 1].value;
}

void midorderTrace(Tree* tr) {
    stack<A*> st;
    st.push(tr);
    A* a = st.top();
    while (tr != nullptr && !st.empty()) {
        while (a != nullptr) {
            st.push(a);
            a = a->left;
        }
        if (!st.empty()) {
            a = st.top();
            cout << "node " << a->no << endl;
            st.pop();
            a = a->right;
        }
    }
}

void broadTrace(Tree* tr) {
    queue<A*> q;
    q.push(tr);
    A* a = q.front();
    while (tr != nullptr && !q.empty()) {
        a = q.front();
        cout << a->no << "<L, R> = <" << a->start <<", " << a->end<< ">" << endl;
        q.pop();
        if (a->left != nullptr) q.push(a->left);
        if (a->right != nullptr) q.push(a->right);
    }
}

int main(void) {
    int N;
    cin >> N;
    Tree* tree = new Tree[3 * N + 1];
    buildTree(tree, 1, 1, N);
    midorderTrace(&(tree[1]));
    broadTrace(&(tree[1]));
    return 1;
}
