#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static string ito36(int N) {
    if (N < 0) return std::to_string(N);
    static string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count = 0;
    int base = 36;
    int res = N;
    string s;
    while (res) {
        int idx = res % 36;
        res = res / 36;
        s.push_back(digits[idx]);
    }
    int i = s.length();
    while (i++ < 4) s.push_back('0');
    std::reverse(s.begin(), s.end());
    return s;
}

int main(void) {
    int N;
    cin >> N;
    cout << ito36(N) << endl;
    return 0;
}
