/**
 *    author:  MaGnsi0
 *    created: 22.07.2023 13:27:22
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 80, M = 128;
const int64_t MOD = 1e9 + 7;

string n;
int64_t t = 0, id[N][3 * N][M][2][2], P10[3 * N];
pair<int64_t, int64_t> dp[N][3 * N][M][2][2];

pair<int64_t, int64_t> solve(int i, int j, int64_t val, int tie, int started) {
    if (i == N) { return (j == 0 ? make_pair(0, 1) : make_pair(0, 0)); }
    if (j <= 0) { return make_pair(0, 0); }
    auto& res = dp[i][j][val][tie][started];
    if (id[i][j][val][tie][started] == t) { return res; }
    id[i][j][val][tie][started] = t;
    res = {0, 0};
    for (int d = 0; d <= (tie ? n[i] - '0' : 9); ++d) {
        int64_t nval = val ^ (d * d);
        int nj = j - to_string(nval).size();
        if (nval == 0 && !started) { nj = j; }
        if (nj < 0) { continue; }
        auto add = solve(i + 1, nj, nval, tie && (d == n[i] - '0'), started || nval);
        res.first += add.first + (add.second * P10[nj] % MOD * nval) % MOD;
        res.second += add.second;
        res.first %= MOD;
        res.second %= MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("legendary.in", "r", stdin);
    P10[0] = 1;
    for (int i = 1; i < 3 * N; ++i) {
        P10[i] = P10[i - 1] * 10 % MOD;
    }
    memset(id, -1, sizeof id);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        reverse(n.begin(), n.end());
        while ((int)n.size() < N) { n += "0"; }
        reverse(n.begin(), n.end());
        int64_t ans = 0;
        for (int s = 1; s < 3 * N; ++s) {
            int64_t val = solve(0, s, 0, 1, 0).first;
            ans = (ans + val) % MOD;
        }
        cout << ans << "\n";
        t++;
    }
}
