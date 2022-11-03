/**
 *    author:  MaGnsi0
 *    created: 01.10.2022 22:01:27
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 66, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }
    vector<int> win(N), tie(N), lose(N);
    win[1] = tie[1] = 1;
    for (int i = 2; i < N / 2; ++i) {
        win[i] = (C[2 * i - 1][i - 1] + lose[i - 1]) % MOD;
        tie[i] = 1;
        lose[i] = (C[2 * i][i] - win[i] - tie[i] + MOD) % MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << win[n / 2] << " " << lose[n / 2] << " " << tie[n / 2] << "\n";
    }
}
