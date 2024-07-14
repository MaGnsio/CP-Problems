/**
 *    author:  MaGnsi0
 *    created: 14.07.2024 17:58:38
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 20;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), f(1 << M);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; f[a[i]]++;
    }
    vector<vector<int>> dp1(1 << M, vector<int>(M, 0));
    for (int mask = 1; mask < (1 << M); ++mask) {
        dp1[mask][0] = f[mask] + (mask & 1 ? f[mask ^ 1] : 0);
        for (int x = 1; x < M; ++x) {
            int p = 1 << x;
            dp1[mask][x] = dp1[mask][x - 1] + (mask & p ? dp1[mask ^ p][x - 1] : 0);
        }
    }
    vector<vector<int>> dp2(1 << M, vector<int>(M, 0));
    for (int mask = (1 << M) - 2; mask > 0; --mask) {
        dp2[mask][0] = f[mask] + (mask & 1 ^ 1 ? f[mask ^ 1] : 0);
        for (int x = 1; x < M; ++x) {
            int p = 1 << x;
            dp2[mask][x] = dp2[mask][x - 1] + (mask & p ^ p ? dp2[mask ^ p][x - 1] : 0);
        }
    }
    for (int x : a) {
        cout << dp1[x][M - 1] << " " << dp2[x][M - 1] << " " << n - dp1[x ^ ((1 << M) - 1)][M - 1] << "\n";
    }
}
