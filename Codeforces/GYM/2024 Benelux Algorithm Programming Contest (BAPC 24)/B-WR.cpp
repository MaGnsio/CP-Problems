/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 23:14:16
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector adj(n, vector<int>(4, -1));
    for (int i = 0; i < n; ++i) {
        cin >> adj[i][0] >> adj[i][2]; //n e
        cin >> adj[i][1] >> adj[i][3]; //s w
        adj[i][0]--, adj[i][2]--;
        adj[i][1]--, adj[i][3]--;
    }
    int dir[4][4] = {{0, 1, 2, 3},
                     {1, 0, 3, 2},
                     {2, 3, 0, 1},
                     {3, 2, 1, 0}};
    set<tuple<int, int, int, int>> S;
    vector ans(n, vector(4, vector<int>(k + 1, OO)));
    for (int i = 0; i < 4; ++i) {
        ans[0][i][0] = 0; S.emplace(0, 0, i, 0);
    }
    while (!S.empty()) {
        auto [ans_v, v, d, t] = *S.begin(); S.erase(S.begin());
        if (ans[v][d][t] != ans_v) { continue; }
        for (int nd_ = 0; nd_ < 4; ++nd_) {
            int nd = dir[d][nd_];
            if ((d ^ nd) == 1) { continue; }
            if (adj[v][nd] == -1) { continue; }
            int nt = t + (d != nd);
            if (nt > k) { continue; }
            int nv = adj[v][nd];
            if (ans[nv][nd][nt] > ans_v + 1) {
                ans[nv][nd][nt] = ans_v + 1;
                S.emplace(ans_v + 1, nv, nd, nt);
            }
        }
    }
    int res = OO;
    for (int d = 0; d < 4; ++d) {
        for (int t = 0; t <= k; ++t) {
            res = min(res, ans[n - 1][d][t]);
        }
    }
    if (res == OO) {
        cout << "impossible";
    } else {
        cout << res;
    }
}
