/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 22:22:36
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
    void build(int p, int l, int r) {
        if (l == r) {
            segTree[p] = A[l];
        } else {
            int m = (l + r) / 2;
            build(L(p), l, m);
            build(R(p), m + 1, r);
            segTree[p] = compine(segTree[L(p)], segTree[R(p)]);
        }
    }
    void propagate(int p, int l, int r) {
        if (lazyPropagation[p] == 0) {
            return;
        }
        segTree[p] = max(segTree[p], lazyPropagation[p]);
        if (l != r) {
            lazyPropagation[L(p)] = lazyPropagation[R(p)] = lazyPropagation[p];
        } else {
            A[l] = lazyPropagation[p];
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
        A = vector<int>(N, 0);
        segTree = vector<int>(4 * n, 0);
        lazyPropagation = vector<int>(4 * n, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; ++i) {
        c[a[i]].first = i;
        c[b[i]].second = i;
    }
    sort(c.begin(), c.end(), greater<pair<int, int>>());
    segment_tree st(n);
    for (int i = 0; i < n; ++i) {
        int x = st.query(1, 0, n - 1, c[i].second + 1, n - 1) + 1;
        st.update(1, 0, n - 1, x, c[i].second, c[i].second);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, st.query(1, 0, n - 1, i, i));
    }
    cout << res;
}
