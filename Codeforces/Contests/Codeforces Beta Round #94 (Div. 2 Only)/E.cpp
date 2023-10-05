/**
 *    author:  MaGnsi0
 *    created: 17.03.2022 13:20:27
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 3, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }
    int n, m, k;
    cin >> n >> m >> k;
    cout << (1LL * C[n - 1][2 * k] * C[m - 1][2 * k]) % MOD;
}
