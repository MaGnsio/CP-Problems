/**
 *    author:  MaGnsi0
 *    created: 08.02.2023 18:37:09
**/
#include <bits/stdc++.h>

using namespace std;

bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int>& A, vector<int>& B) {
    if (A[a] != L) { return false; }
    A[a] = -1;
    for (auto& b : g[a]) {
        if (B[b] == L + 1) {
            B[b] = 0;
            if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B)) {
                btoa[b] = a;
                return true;
            }
        }
    }
    return false;
}

int hopcroft_karp(vector<vector<int>>& g, vector<int> btoa) {
    int res = 0;
    vector<int> A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(A.begin(), A.end(), 0);
        fill(B.begin(), B.end(), 0);
        cur.clear();
        for (auto& a : btoa) {
            if(a != -1) { A[a] = -1; }
        }
        for (int a = 0; a < (int)g.size(); ++a) {
            if(A[a] == 0) { cur.push_back(a); }
        }
        for (int lay = 1;; ++lay) {
            bool islast = 0;
            next.clear();
            for (auto& a : cur) {
                for (auto& b : g[a]) {
                    if (btoa[b] == -1) {
                        B[b] = lay;
                        islast = 1;
                    } else if (btoa[b] != a && !B[b]) {
                        B[b] = lay;
                        next.push_back(btoa[b]);
                    }
                }
            }
            if (islast) { break; }
            if (next.empty()) { return res; }
            for (auto& a : next) { A[a] = lay; }
            cur.swap(next);
        }
        for (int a = 0; a < (int)g.size(); ++a) {
            res += dfs(a, 0, g, btoa, A, B);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
    }
    function<bool(int)> F = [&](int x) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            if (w[i] <= x) {
                adj[u[i] - 1].push_back(v[i] - 1);
            }
        }
        return hopcroft_karp(adj, vector<int>(n, -1)) == n;
    };
    int low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (F(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
