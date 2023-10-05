/**
 *    author:  MaGnsi0
 *    created: 15.04.2023 23:34:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<void(int)> add = [&](int x) {
        cout << "+ " << x << endl;
        int response;
        cin >> response;
        if (response == -2) { exit(0); }
    };
    function<int(int, int)> ask = [&](int i, int j) {
        cout << "? " << i + 1 << " " << j + 1 << endl;
        int response;
        cin >> response;
        if (response == -2) { exit(0); }
        return response;
    };
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        add(n), add(n + 1);
        for (int i = 1; i <= n; ++i) {
            int u = i, v = n - i;
            if (u == v) { continue; }
            if (v <= 0) { continue; }
            adj[u - 1].push_back(v - 1);
        }
        for (int i = 1; i <= n; ++i) {
            int u = i, v = n - i + 1;
            if (u == v) { continue; }
            if (v <= 0) { continue; }
            adj[u - 1].push_back(v - 1);
        }
        pair<int, int> k = {0, 0};
        for (int i = 1; i < n; ++i) {
            k = max(k, make_pair(ask(0, i), i));
        }
        vector<int> s(2);
        vector<vector<int>> d(2, vector<int>(n, -1)), q(2);
        s[0] = n - 1, s[1] = (n + 1) / 2 - 1;
        for (int _ = 0; _ < 2; _++) {
            d[_][s[_]] = 0, q[_].push_back(s[_]);
            while (q[_].size() < n) {
                int v = q[_].back();
                for (auto& u : adj[v]) {
                    if (d[_][u] == -1) {
                        d[_][u] = d[_][v] + 1;
                        q[_].push_back(u);
                    }
                }
            }
        }
        vector<vector<int>> ans(2, vector<int>(n));
        ans[0][k.second] = s[0], ans[1][k.second] = s[1];
        for (int i = 0; i < n; ++i) {
            if (i == k.second) { continue; }
            int x = ask(i, k.second);
            assert(x != -1);
            for (int _ = 0; _ < 2; ++_) {
                for (int k = 0; k < n; ++k) {
                    if (d[_][k] == x) {
                        ans[_][i] = k;
                        break;
                    }
                }
            }
        }
        cout << "!";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << " " << ans[i][j] + 1;
            }
        }
        cout << endl;
        int response;
        cin >> response;
        if (response == -1) { exit(0); }
    }
}
