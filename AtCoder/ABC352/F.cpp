/**
 *    author:  MaGnsi0
 *    created: 04.05.2024 18:10:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        int w; cin >> w;
        adj[u].emplace_back(v, -w);
        adj[v].emplace_back(u, +w);
    }
    vector<int> masks, imask(n), pmask(n);
    vector<bool> done(n, false);
    function<vector<int>(vector<int>, int)> shift = [&](vector<int> mask, int o) {
        vector<int> new_mask(n, -1);
        for (int i = 0; i < n; ++i) {
            if (i - o < 0) { continue; }
            new_mask[i] = mask[i - o];
        }
        mask = new_mask;
        for (int i = 0; i < n; ++i) {
            if (mask[i] == -1) { continue; }
            pmask[mask[i]] = i;
        }
        return mask;
    };
    function<void(int)> make_mask = [&](int start) {
        queue<int> q;
        vector<int> mask(n, -1);
        q.push(start);
        mask[0] = start;
        pmask[start] = 0;
        done[start] = true;
        imask[start] = (int)masks.size();
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto [u, w] : adj[v]) {
                if (done[u]) { continue; }
                int p = pmask[v];
                if (w < 0) {
                    if (p + w < 0) {
                        mask = shift(mask, abs(p + w));
                        p = pmask[v];
                        assert(p + w >= 0);
                    }
                } else {
                    assert(p + w < n);
                }
                q.push(u);
                done[u] = true;
                mask[p + w] = u;
                pmask[u] = p + w;
                imask[u] = (int)masks.size();
            }
        }
        int maskb = 0;
        for (int i = 0; i < n; ++i) {
            if (mask[i] != -1) {
                maskb |= 1 << i;
            }
        }
        masks.push_back(maskb);
    };
    for (int i = 0; i < n; ++i) {
        if (done[i]) { continue; }
        make_mask(i);
    }
    int k = (int)masks.size(), to_skip = -1;
    vector<vector<int>> dp(k, vector<int>(1 << n, -1));
    function<int(int, int)> solve = [&](int j, int filled) {
        if (filled >= (1 << n)) { return 0; }
        if (j == k) {
            return int(filled == (1 << n) - 1);
        }
        if (dp[j][filled] != -1) {
            return dp[j][filled];
        }
        if (j == to_skip) {
            return dp[j][filled] = solve(j + 1, filled);
        }
        dp[j][filled] = 0;
        for (int s = 0; s < n; ++s) {
            if ((masks[j] << s) & filled) { continue; }
            dp[j][filled] = max(dp[j][filled], solve(j + 1, (masks[j] << s) | filled));
        }
        return dp[j][filled];
    };
    for (int i = 0; i < n; ++i) {
        to_skip = imask[i];
        set<int> pos;
        for (int j = pmask[i]; j < n; ++j) {
            int mask = masks[imask[i]] << (j - pmask[i]);
            if (solve(0, mask)) {
                pos.insert(j + 1);
            }
        }
        cout << ((int)pos.size() == 1 ? *pos.begin() : -1) << " ";
    }
}
