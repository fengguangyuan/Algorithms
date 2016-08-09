#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

/********
**  greed approach to find an optimal result
**
********/

void preHandle(int N) {
    set<std::pair<int, int> > cnt_num;
    map<int, int> table;

    int number = 0;
    int n = N;
    while (n--) {
        cin >> number;
        if (number < 1 || number > 1000000000) return;
        table[number]++;
    }

    for (auto it : table) cnt_num.insert({it.second, it.first});
    if ((--cnt_num.end())->first * 2 - 1 > N) {
        cout << -1 << endl;
        return;
    }

    int prev = -1;
    for (int i = 1; i <= N; i++) {
        int pick = -1;
        if ((--cnt_num.end())->first * 2 - 1 == N - i + 1) {
            // select the most duplications
            pick = (--cnt_num.end())->second;
        } else {
            // select the smallest number
            if (table.begin()->first == prev) pick = (++table.begin())->first;
            else pick = table.begin()->first;
        }

        // delete it from set<pair<int, int> >
        cnt_num.erase(std::make_pair(table[pick], pick));
        // if the picked number has more duplications, then put it into set<pair<int, int> > again
        if (--table[pick] > 0) cnt_num.insert(std::make_pair(table[pick], pick));
        // or delete it from map<int, int> synchronously
        else table.erase(pick);

        cout << pick << " ";
        // record the number output last time.
        prev = pick;
    }
}

int main(void) {
    int N;
    cin >> N;
    preHandle(N);
    return 1;
}
