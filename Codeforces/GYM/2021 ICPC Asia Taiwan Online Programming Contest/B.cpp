/**
 *    author:  MaGnsi0
 *    created: 14.11.2021 16:22:33
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<long long> S(N, 1);
    S[1] = 0;
    for (int i = 2; i < N; ++i) {
        for (int j = 2 * i; j < N; j += i) {
            S[j] += 1LL * i;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        if (S[n] > n) {
            cout << "abundant\n";
        } else if (S[n] < n) {
            cout << "deficient\n";
        } else {
            cout << "perfect\n";
        }
    }
}
