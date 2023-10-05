/**
 *    author:  MaGnsi0
 *    created: 03.01.2023 18:05:33
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int m;
        cin >> m;
        vector<int> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            ok &= b[i] <= a[i];
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[b[i]].push_back(i);
        }
        segment_tree<int> d(n, 0, [](int x, int y) { return max(x, y); });
        for (int i = 0; i < n; ++i) {
            d.update(i, b[i]);
        }
        vector<vector<int>> adj(n);
        for (auto& [x, v] : mp) {
            for (int i = 0; i + 1 < (int)v.size(); ++i) {
                int l = v[i], r = v[i + 1];
                if (d.query(l, r) <= b[l]) {
                    adj[l].push_back(r);
                }
            }
        }
        vector<bool> visited(n, false);
        map<int, int> r;
        function<bool(int)> dfs = [&](int v) {
            visited[v] = true;
            bool ans = b[v] == a[v];
            for (auto& u : adj[v]) {
                ans &= dfs(u);
            }
            return ans;
        };
        for (int i = 0; i < m; ++i) {
            r[c[i]]++;
        }
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            bool noneed = dfs(i);
            if (noneed == true) {
                continue;
            }
            if (r.count(b[i]) == 0) {
                ans = false;
                break;
            }
            r[b[i]]--;
            if (r[b[i]] == 0) {
                r.erase(b[i]);
            }
            dfs(i);
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
}
