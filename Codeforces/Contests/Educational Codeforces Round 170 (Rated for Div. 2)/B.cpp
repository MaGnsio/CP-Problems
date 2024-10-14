/**
 *    author:  MaGnsi0
 *    created: 14.10.2024 17:40:33
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t Nax = 1e5 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> P2(Nax, 1);
    for (int i = 1; i < Nax; ++i) {
        P2[i] = 2LL * P2[i - 1] % MOD;
    }
    int T; cin >> T;
    vector<int> N(T), K(T);
    for (int i = 0; i < T; ++i) {
        cin >> N[i];
    }
    for (int i = 0; i < T; ++i) {
        cin >> K[i];
    }
    for (int i = 0; i < T; ++i) {
        cout << P2[K[i]] << "\n";
    }
}
