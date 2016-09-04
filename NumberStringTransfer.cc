#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

void printDiffNum() {
    int N;
    // accept a number as hex
    cin >> N;
    cout << "hex : " << hex << N << endl;
    // base 8
    cout << "oct : " << oct << N << endl;
    // base 10
    cout << "dec : " << dec << N << endl;
    // or use manipulation method
    int base;
    cout << " please input a base number " << endl;
    cin >> base;
    cout << "any base : " << setbase(base) << N << endl;
}

void string2num() {
    cout << "sstream test...it only can transfer a decimal to a string!" << endl;
    stringstream ss;
    int N;
    cin >> N;
    ss << N;
    string s_n;
    ss >> s_n;
    cout << "num length: " << s_n.length() << ", content: " << s_n << endl;
    cout << "but stoi/stol/stoll can be used to change base, like:" << endl;
    cout << "hex: " << stoi(s_n, 0, 16) << endl;
    cout << "oct: " << stoi(s_n, 0, 8) << endl;
    cout << "dec: " << stoi(s_n, 0, 10) << endl;

}
void num2string() {
    int i = 100;
    long l = 100000000;
    float f = 2.3;
    cout << "int: " << i
        << ", string: " << to_string(i) << endl
        << "long: " << l << ", string: " << to_string(l) << endl
        << "float: " << f << ", string: " << to_string(f) << endl;
}

int main(void) {
    printDiffNum();
    string2num();
    num2string();
    return 0;
}
