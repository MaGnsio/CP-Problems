/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 18:09:43
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const string narek = "narek";

int n, m, dp[N][5], T[N][5], t = 0;
string a[N];

int solve(int x, int z) {
    if (x == n) { return -z; }
    if (T[x][z] == t) { return dp[x][z]; }
    T[x][z] = t;
    dp[x][z] = solve(x + 1, z);
    int z_ = z, score = 0;
    for (int i = 0; i < m; ++i) {
        if (a[x][i] == narek[z_]) {
            score += 5 * (z_ == 4);
            z_ = (z_ + 1) % 5;
        } else if (a[x][i] == 'n' || a[x][i] == 'a' || a[x][i] == 'r' || a[x][i] == 'e' || a[x][i] == 'k') {
            score--;
        }
    }
    dp[x][z] = max(dp[x][z], solve(x + 1, z_) + score);
    return dp[x][z];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(T, -1, sizeof T);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = solve(0, 0);
        cout << ans << "\n";
        t++;
    }
}
