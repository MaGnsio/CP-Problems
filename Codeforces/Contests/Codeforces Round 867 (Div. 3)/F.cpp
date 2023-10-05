/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 17:44:32
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e10;

struct Node {
    Node *l = 0, *r = 0;
    int64_t lo, hi, mset = OO, madd = 0, val = -OO;
    Node(int lo, int hi) : lo(lo), hi(hi) {}
    Node(vector<int64_t>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = max(l -> val, r -> val);
        } else {
            val = v[lo];
        }
    }
    int64_t query(int L, int R) {
        if (R <= lo || hi <= L) return -OO;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l -> query(L, R), r -> query(L, R));
    }
    void set(int L, int R, int64_t x) {
        if (R <= lo || hi <= L) { return; }
        if (L <= lo && hi <= R) {
            mset = val = x, madd = 0;
        } else {
            push(), l -> set(L, R, x), r -> set(L, R, x);
            val = max(l -> val, r -> val);
        }
    }
    void add(int L, int R, int64_t x) {
        if (R <= lo || hi <= L) { return; }
        if (L <= lo && hi <= R) {
            if (mset != OO) {
                mset += x;
            } else {
                madd += x;
            }
            val += x;
        } else {
            push(), l -> add(L, R, x), r -> add(L, R, x);
            val = max(l -> val, r -> val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != OO) {
            l -> set(lo, hi, mset), r -> set(lo, hi, mset), mset = OO;
        } else if (madd) {
            l -> add(lo, hi, madd), r -> add(lo, hi, madd), madd = 0;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k, c;
        cin >> n >> k >> c;
        vector<vector<int>> adj(n);
        for (int i = 0; i + 1 < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        int t = 0;
        vector<int64_t> d(n), in(n), out(n), tree;
        function<void(int, int)> dfs = [&](int v, int p) {
            in[v] = t++;
            tree.push_back(v);
            for (int u : adj[v]) {
                if (u == p) { continue; }
                d[u] = d[v] + 1;
                dfs(u, v);
            }
            out[v] = t++;
            tree.push_back(v);
        };
        d[0] = 0;
        dfs(0, -1);
        assert((int)tree.size() == 2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            tree[i] = d[tree[i]];
        }
        int64_t ans = 0;
        Node b(tree, 0, 2 * n);
        function<void(int, int)> reroot = [&](int v, int p) {
            ans = max(ans, k * b.query(0, 2 * n) - c * d[v]);
            for (auto& u : adj[v]) {
                if (u == p) { continue; }
                b.add(0, 2 * n, 1);
                b.add(in[u], out[u] + 1, -2);
                reroot(u, v);
                b.add(0, 2 * n, -1);
                b.add(in[u], out[u] + 1, 2);
            }
        };
        reroot(0, -1);
        cout << ans << "\n";
    }
}
