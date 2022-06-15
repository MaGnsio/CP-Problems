/**
 *    author:  MaGnsi0
 *    created: 14.04.2022 21:58:58
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1);
    for (int i = 2; i < N; ++i) {
        F[i] = F[i - 1] + F[i - 2];
        F[i] %= MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        cout << F[n] << "\n";
    }
}
