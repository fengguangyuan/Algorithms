#include <iostream>
using namespace std;

void adjustHeap(int m[], int pos, int N) {
    int k = pos;
    while ( 2 * k <= N) {
        int x = m[k];
        int max_idx = 2 * k;
        if (2 * k + 1 <= N && m[max_idx] < m[2 * k + 1])
            max_idx = 2 * k + 1;

        max_idx = m[max_idx] < m[k] ? k : max_idx;

        if (max_idx == k) break;

        m[k] = m[max_idx];
        m[max_idx] = x;
        k = max_idx;
    }
}

void buildHeap(int m[], int N) {
    int p = N / 2;
    while (p > 0) {
        adjustHeap(m, p, N);
        p--;
    }
}

void heapSort(int m[], int N) {
    buildHeap(m, N);

    for (int i = N; i > 0; i--) {
        int temp = m[i];
        m[i] = m[1];
        m[1] = temp;

        adjustHeap(m, 1, i - 1);
    }
}

int main(void) {
    int m[11] = {-1, 24, 4, 15, 5, 40, 100, 9, 43, 10, 11};
    for (int i = 1; i < 11; i++) cout << m[i] << " ";
    cout << endl;
    heapSort(m, 10);
    for (int i = 1; i < 11; i++) cout << m[i] << " ";
    cout << endl;
    return 0;
}
