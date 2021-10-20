/**
 *    author:  MaGnsi0
 *    created: 06/08/2021 19:57:26
**/
#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    int N;
    vector<int> A, segTree, lazyPropagation;
    int L(int p) {
        return (p << 1);
    }
    int R(int p) {
        return (p << 1) + 1;
    }
    int compine(int a, int b) {
        return max(a, b);
    }
    void propagate(int p, int l, int r) {
        if (lazyPropagation[p] == -1) {
            return;
        }
        segTree[p] = max(segTree[p], lazyPropagation[p]);
        if (l != r) {
            lazyPropagation[L(p)] = max(lazyPropagation[L(p)], lazyPropagation[p]);
            lazyPropagation[R(p)] = max(lazyPropagation[R(p)], lazyPropagation[p]);
        } else {
            A[l] = max(A[l], lazyPropagation[p]);
        }
        lazyPropagation[p] = -1;
    }
    int query(int p, int l, int r, int i, int j) {
        propagate(p, l, r);
        if (i > j) {
            return -1;
        }
        if (i <= l && r <= j) {
            return segTree[p];
        }
        int m = (l + r) / 2;
        return compine(query(L(p), l, m, i, min(m, j)), query(R(p), m + 1, r, max(i, m + 1), j));
    }
    void update(int p, int l, int r, int v, int i, int j) {
        propagate(p, l, r);
        if (i > j) {
            return;
        }
        if (i <= l && r <= j) {
            lazyPropagation[p] = v;
            propagate(p, l, r);
        } else {
            int m = (l + r) / 2;
            update(L(p), l, m, v, i, min(m, j));
            update(R(p), m + 1, r, v, max(i, m + 1) , j);
            propagate(L(p), l, m);
            propagate(R(p), m + 1, r);
            segTree[p] = compine(segTree[L(p)], segTree[R(p)]);
        }
    }
    segment_tree(int n) {
        N = n;
        A = vector<int>(n, -1);
        segTree = vector<int>(4 * n, -1);
        lazyPropagation = vector<int>(4 * n, -1);
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    segment_tree st(n);
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, w;
            cin >> l >> r >> w;
            l--, r--;
            st.update(1, 0, n - 1, r, l, r);
        } else {
            int k, cnt = 0, cur = -1, ok = 1;
            cin >> k;
            for (int i = 0; i < k; ++i) {
                int x;
                cin >> x;
                x--;
                if (cur < x) {
                    cur = st.query(1, 0, n - 1, x, x);
                    cnt++;
                    if (cur == -1) {
                        ok = 0;
                    }
                }
            }
            cout << (ok ? cnt : -1) << "\n";
        }
    }
}
