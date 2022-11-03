/**
 *    author:  MaGnsi0
 *    created: 27.10.2022 01:53:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m, MOD;
    cin >> n >> m >> MOD;
    vector<int64_t> L(m), R(m), V(m);
    for (int i = 0; i < m; ++i) {
        cin >> L[i] >> R[i] >> V[i];
    }
    vector<vector<pair<int, int64_t>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        adj[L[i] - 1].emplace_back(R[i], V[i]);
        adj[R[i]].emplace_back(L[i] - 1, V[i]);
    }
    vector<int64_t> P(n + 1);
    vector<bool> D(n + 1, false);
    function<void(int)> set_valuesP = [&](int x) {
        D[x] = true;
        for (auto& [y, v] : adj[x]) {
            if (D[y]) { continue; }
            if (x < y) {
                P[y] = (P[x] + v) % MOD;
            } else {
                P[y] = (P[x] - v + MOD) % MOD;
            }
            set_valuesP(y);
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (D[i]) { continue; }
        P[i] = (i ? P[i - 1] : 0);
        set_valuesP(i);
    }
    for (int i = 0; i < m; ++i) {
        if ((P[R[i]] - P[L[i] - 1] + MOD) % MOD != V[i]) {
            cout << "None";
            return 0;
        }
    }
    vector<int64_t> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        A[i] = (P[i] - P[i - 1] + MOD) % MOD;
    }
    for (int i = 1; i <= n; ++i) {
        cout << A[i] << " ";
    }
}
