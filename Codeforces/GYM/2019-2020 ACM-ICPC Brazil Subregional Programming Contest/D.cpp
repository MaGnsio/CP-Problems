/**
 *    author:  MaGnsi0
 *    created: 31.10.2023 21:32:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector<int> p(n, -1);
    for (int i = 1; i < n; ++i) {
        cin >> p[i]; p[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        adj[p[i]].push_back(i);
    }
    int dfs_time = 0;
    vector<int> tin(n), tout(n), ps(n);
    function<void(int, int)> dfs = [&](int v, int c) {
        tin[v] = dfs_time++, ps[v] = c;
        for (int u : adj[v]) {
            dfs(u, c + 1);
        }
        tout[v] = dfs_time++;
    };
    dfs(0, 1);
    vector<int> t(2 * n, -1);
    for (int i = 0; i < n; ++i) {
        t[tin[i]] = i;
    }
    vector<int> c(8 * n);
    vector<pair<int, int>> b(8 * n, {-1, -1});
    function<void(int)> push = [&](int j) {
        c[2 * j + 1] += c[j];
        c[2 * j + 2] += c[j];
        b[2 * j + 1].first += c[j];
        b[2 * j + 2].first += c[j];
        c[j] = 0;
    };
    function<void(int, int, int)> build = [&](int j, int low, int high) {
        if (low > high) { return; }
        if (low == high) {
            int v = t[low];
            b[j] = {(v == -1 ? -1 : ps[v]), v};
            return;
        }
        int mid = (low + high) / 2;
        build(2 * j + 1, low, mid);
        build(2 * j + 2, mid + 1, high);
        b[j] = max(b[2 * j + 1], b[2 * j + 2]);
    };
    build(0, 0, 2 * n - 1);
    function<void(int, int, int, int, int)> update = [&](int j, int low, int high, int from, int to) {
        if (low > high) { return; }
        if (high < from || to < low) { return; }
        if (from <= low && high <= to) {
            b[j].first -= 1;
            if (low != high) {
                c[j] -= 1;
                push(j);
            }
        } else {
            push(j);
            int mid = (low + high) / 2;
            update(2 * j + 1, low, mid, from, to);
            update(2 * j + 2, mid + 1, high, from, to);
            b[j] = max(b[2 * j + 1], b[2 * j + 2]);
        }
    };
    function<pair<int, int>(int, int, int, int, int)> query = [&](int j, int low, int high, int from, int to) {
        if (low > high) { return make_pair(-1, -1); }
        if (high < from || to < low) { return make_pair(-1, -1); }
        if (from <= low && high <= to) {
            return b[j];
        }
        push(j);
        int mid = (low + high) / 2;
        return max(query(2 * j + 1, low, mid, from, to), query(2 * j + 2, mid + 1, high, from, to));
    };
    int ans = 0;
    vector<bool> done(n, false);
    while (k-- && ans < n) {
        int v = query(0, 0, 2 * n - 1, 0, 2 * n - 1).second;
        while (v != -1 && !done[v]) {
            update(0, 0, 2 * n - 1, tin[v], tout[v]);
            done[v] = true;
            v = p[v];
            ans++;
        }
    }
    cout << ans;
}
