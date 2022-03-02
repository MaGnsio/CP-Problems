/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 00:49:01
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

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
        return (a + b);
    }
    void propagate(int p, int l, int r) {
        segTree[p] += (r - l + 1) * lazyPropagation[p];
        if (l != r) {
            lazyPropagation[L(p)] += lazyPropagation[p];
            lazyPropagation[R(p)] += lazyPropagation[p];
        } else {
            A[l] += lazyPropagation[p];
        }
        lazyPropagation[p] = 0;
    }
    int query(int p, int l, int r, int i, int j) {
        propagate(p, l, r);
        if (i > j) {
            return 0;
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
        A = vector<int>(n, 0);
        segTree = vector<int>(4 * n, 0);
        lazyPropagation = vector<int>(4 * n, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        segment_tree st(N);
        cout << "Case #" << t << ":";
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            st.update(1, 0, N - 1, 1, 1, x);
            int l = 1, r = N - 1, res = 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (st.query(1, 0, N - 1, m, m) >= m) {
                    res = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            cout << " " << res;
        }
        cout << "\n";
    }
}
