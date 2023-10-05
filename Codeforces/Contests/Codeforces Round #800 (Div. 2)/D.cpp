/**
 *    author:  MaGnsi0
 *    created: 17.06.2022 18:17:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> P(n);
        for (int i = 1; i < n; ++i) {
            cin >> P[i];
            P[i]--;
        }
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[P[i]].push_back(i);
        }
        vector<int64_t> L(n), R(n);
        for (int i = 0; i < n; ++i) {
            cin >> L[i] >> R[i];
        }
        int ans = 0;
        function<int64_t(int)> DFS = [&](int v) {
            if (adj[v].empty()) { //i.e. leaf node
                ans++;
                return R[v]; //we have to make an operation on this node
            }
            int64_t add = 0;
            for (auto& u : adj[v]) {
                add += DFS(u);
            }
            if (add < L[v]) { //i.e. making operation on nodes that add to this nodes is not sufficient
                ans++;
                return R[v]; //we have to make an operation on this node
            }
            return min(R[v], add);
        };
        DFS(0);
        cout << ans << "\n";
    }
}
