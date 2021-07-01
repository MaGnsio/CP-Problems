//https://atcoder.jp/contests/abc199/tasks/abc199_b
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, L = INT_MIN, R = INT_MAX;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) {
            cout << 0;
            return 0;
        }
        L = max(L, A[i]), R = min(R, B[i]);
    }
    cout << max(R - L + 1, 0);
}
