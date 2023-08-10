/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 18:19:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int64_t> L(m), R(m), V(m);
        for (int i = 0; i < m; ++i) {
            cin >> L[i] >> R[i] >> V[i];
            if (L[i] > R[i]) {
                swap(L[i], R[i]);
            } else {
                V[i] *= -1;
            }
        }
        vector<vector<pair<int, int64_t>>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            adj[L[i]].emplace_back(R[i], V[i]);
            adj[R[i]].emplace_back(L[i], V[i]);
        }
        vector<int64_t> P(n + 1);
        vector<bool> D(n + 1, false);
        function<void(int)> set_valuesP = [&](int x) {
            D[x] = true;
            for (auto& [y, v] : adj[x]) {
                if (D[y]) { continue; }
                if (x < y) {
                    P[y] = (P[x] + v);
                } else {
                    P[y] = (P[x] - v);
                }
                set_valuesP(y);
            }
        };
        for (int i = 1; i <= n; ++i) {
            if (D[i]) { continue; }
            P[i] = (i ? P[i - 1] : 0);
            set_valuesP(i);
        }
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            if (P[R[i]] - P[L[i]] != V[i]) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
