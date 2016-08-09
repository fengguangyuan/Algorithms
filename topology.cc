#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

void genGraph(vector<vector<int> > &tmp, int* outDegrees, int N) {
    if (N < 0) return;
    tmp.resize(N);
    for (int i = 0; i < N; i++)
        tmp[i].resize(N);

    for (int i = 0; i < N; i++) {
        int count = 0;
        cin >> count;
        for (int j = 0; j < count; j++) {
            int mentor = 0;
            cin >> mentor;
            if (mentor != 0) {
                tmp[i][mentor - 1] = 1;
                outDegrees[i] += 1;
            }
        }
    }
}

// bfs
bool IsStable(vector<vector<int> > &g, set<int> &stables, int N, int index) {
    if (stables.find(index) != stables.end()) return true;

    //cout << "searching from " << index + 1 << endl;
    set<int> tmp;
    queue<int> q;
    q.push(index);
    while (!q.empty()) {
        int member = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (g[member][i] == 1)
                if (stables.find(i) != stables.end()) {
    //                cout << "IsSatble(): push " << i+1 << endl;;
                    tmp.insert(i);
                } else {
                    q.push(i);
                }

        }
    }
    return tmp.size() > 1;
}

set<int> topology(vector<vector<int> > &g, int* outDeg, int N) {
    queue<int> qu;
    set<int> stables;
    int* ss = new int[N];
    memset(ss, 0, N);

    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (outDeg[i] == 0) {
            st.push(i);
            ss[i] = 1;
            stables.insert(i);
        }
    }
    while (!st.empty()) {
        int prevSize = st.size();
        int member = st.top();
        qu.push(member);
        st.pop();
        for (int i = 0; i < N; i++) {
            if (g[i][member] == 1) {
                outDeg[i] -= 1;
                if (outDeg[i] == 0) {
                    st.push(i);

                    if (IsStable(g, stables, N, i)) {
                        stables.insert(i);
                        ss[i] = 1;
                    }
                }
            }
        }
    }
    return stables;
}

int main(void) {
    int N = 0;
    cin >> N;

    vector<vector<int> > graph;
    int* outDegrees = new int[N];
    memset(outDegrees, 0, N);
    genGraph(graph, outDegrees, N);

    set<int> vec = topology(graph, outDegrees, N);
    cout << vec.size() << endl;

    return 0;
}
