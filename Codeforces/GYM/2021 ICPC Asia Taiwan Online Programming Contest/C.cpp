/**
 *    author:  MaGnsi0
 *    created: 14.11.2021 16:28:10
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
        return (a + b);
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
        if (lazyPropagation[p] == -1) {
            return;
        }
        segTree[p] = (r - l + 1) * lazyPropagation[p];
        if (l != r) {
            lazyPropagation[L(p)] = lazyPropagation[R(p)] = lazyPropagation[p];
        } else {
            A[l] = lazyPropagation[p];
        }
        lazyPropagation[p] = -1;
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
        A = vector<int>(n, 1);
        segTree = vector<int>(4 * n, 0);
        lazyPropagation = vector<int>(4 * n, -1);
        build(1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long res = 0;
    segment_tree st(n);
    for (int i = 0; i < n; ++i) {
        res += 1LL * st.query(1, 0, n - 1, 0, a[i] - 2);
        st.update(1, 0, n - 1, 0, a[i] - 1, a[i] - 1);
    }
    cout << res;
}
