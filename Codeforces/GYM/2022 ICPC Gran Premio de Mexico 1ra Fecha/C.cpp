/**
 *    author:  MaGnsi0
 *    created: 23.06.2022 07:49:58
**/
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    private:
        int n;
        vector<int64_t> tree, lazy;
    public:
        segment_tree(int n) {
            this -> n = n;
            tree.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }
        void update(int l, int r, int64_t v) {
            update(1, 0, n - 1, l, r, v);
        }
        int query (int64_t k) {
            return query(1, 0, n - 1, k);
        }
    private:
        void update_lazy(int node, int l, int r, int64_t v) {
            lazy[node] += v;
            tree[node] += v * (r - l + 1);
        }
        void push_down(int node, int l, int r) {
            int m = (l + r) / 2;
            update_lazy(2 * node, l, m, lazy[node]);
            update_lazy(2 * node + 1, m + 1, r, lazy[node]);
            lazy[node] = 0;
        }
        void update(int node, int l, int r, int ul, int ur, int v) {
            if (r < ul || l > ur) {
                return;
            }
            if (ul <= l && r <= ur) {
                update_lazy(node, l, r, v);
                return;
            }
            push_down(node, l, r);
            int m = (l + r) / 2;
            update(2 * node, l, m, ul, ur, v);
            update(2 * node + 1, m + 1, r, ul, ur, v);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
        int query(int node, int l, int r, int64_t k) {
            if (l == r) {
                return l;
            }
            push_down(node, l, r);
            int m = (l + r) / 2;
            if (tree[2 * node] >= k) {
                return query(2 * node, l, m, k);
            } else {
                return query(2 * node + 1, m + 1, r, k - tree[2 * node]);
            }
        }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree st(n);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        vector<int64_t> l(k), r(k), x(k);
        for (int j = 0; j < k; ++j) {
            cin >> l[j] >> r[j] >> x[j];
            l[j]--, r[j]--;
        }
        int64_t sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += x[j] * (r[j] - l[j] + 1);
            st.update(l[j], r[j], x[j]);
        }
        int first = st.query((sum + 1) / 2);
        int second = (sum & 1 ? first : st.query((sum + 1) / 2 + 1));
        cout << (a[first] + a[second]) / 2 << ((a[first] + a[second]) & 1 ? ".5\n" : "\n");
        for (int j = 0; j < k; ++j) {
            st.update(l[j], r[j], -x[j]);
        }
    }
}
