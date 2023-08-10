/**
 *    author:  MaGnsi0
 *    created: 19.07.2023 04:10:00
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 17;

int t = 1, f[N], tc[17][N][2];
pair<int, int> dp[17][N][2];

pair<int, int> solve(int i, int mask, int on_parity) {
    if (i == 17) {
        return {on_parity * f[mask], f[mask]};
    }
    pair<int, int>& ans = dp[i][mask][on_parity];
    if (tc[i][mask][on_parity] == t) {
        return ans;
    }
    tc[i][mask][on_parity] = t;
    ans = solve(i + 1, mask, on_parity);
    if (mask >> i & 1) {
        pair<int, int> add = solve(i + 1, mask ^ (1 << i), on_parity ^ 1);
        ans.first += add.first + (on_parity == 0) * add.second;
        ans.second += add.second;
    } else {
        pair<int, int> add = solve(i + 1, mask ^ (1 << i), on_parity);
        ans.first += add.first + add.second;
        ans.second += add.second;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (/*_*/; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            f[a[i]]++;
        }
        int ans = 20 * N;
        for (int i = 0; i < N; ++i) {
            ans = min(ans, solve(0, i, 0).first);
        }
        cout << ans << "\n";
        for (int i = 0; i < n; ++i) {
            f[a[i]]--;
        }
    }
}
