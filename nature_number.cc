#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getDigit(long N) {
    if (N < 10) return (int) N;
    long temp = 0;
    for (int i = 2; i <= 18; i++) {
        long d = i * (pow(10.0, (double)i));
        temp += pow(10.0, (double)(i - 1));
        cout << "d = " << d << endl;
        cout << "temp = " << temp << endl;
        cout << "temp + N = " << (temp + N) << endl;
        if (temp + N < d) {
            d = i * pow(10.0, (double) (i - 1));
            long r = temp + N - d;
            cout << "i = " << i <<endl;
            long num = d / i + r / i;
            std::string s = to_string(num);
            cout << "d = " << d  << ", r = " << r << ", s = " << s << endl;
            long pos = r % i;
            cout << " r % i = " << r % i << ", i = " << i << ", pos = " << pos << endl;
            return s.at(pos) - '0';
        }
    }
    return (int)N;
}

int main(void) {
    long N = 17L;
    cin >> N;

    int res = getDigit(N);
    cout << "Digit " << res << endl;
}
