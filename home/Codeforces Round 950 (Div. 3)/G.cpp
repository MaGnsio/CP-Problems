/**
 *    author:  MaGnsi0
 *    created: 03.06.2024 23:30:18
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    int c, P[2];
    node() { c = 0; P[0] = P[1] = -1; }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            int w; cin >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        vector<int> a(n), b(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            for (auto [u, w] : adj[v]) {
                if (u == p) { continue; }
                a[u] = a[v] ^ w;
                b[u] = b[v] ^ 1;
                dfs(u, v);
            }
        };
        dfs(0, -1);
        vector<node> trie(2);
        function<void(int, int, int)> insert = [&](int val, int root, int add) {
            for (int b = 31; b >= 0; --b) {
                int x = val >> b & 1;
                if (trie[root].P[x] == -1) {
                    trie[root].P[x] = (int)trie.size();
                    trie.push_back(node());
                }
                root = trie[root].P[x];
                trie[root].c += add;
            }
        };
        function<int(int, int)> get = [&](int val, int root) {
            int res = 0;
            for (int b = 31; b >= 0; --b) {
                int x = (val >> b & 1) ^ 1;
                if (trie[root].P[x] == -1 || trie[trie[root].P[x]].c == 0) {
                    if (trie[root].P[x ^ 1] == -1) { return 0; }
                    root = trie[root].P[x ^ 1];
                } else {
                    res += 1 << b;
                    root = trie[root].P[x];
                }
            }
            return res;
        };
        for (int i = 0; i < n; ++i) {
            insert(a[i], b[i], +1);
        }
        int xored = 0;
        while (Q--) {
            char t; cin >> t;
            if (t == '^') {
                int x; cin >> x; xored ^= x;
            } else {
                int v; cin >> v; v--;
                int x; cin >> x;
                insert(a[v], b[v], -1);
                cout << max(get(a[v] ^ x, b[v]), get(a[v] ^ x ^ xored, b[v] ^ 1)) << " ";
                insert(a[v], b[v], +1);
            }
        }
        cout << "\n";
    }
}
