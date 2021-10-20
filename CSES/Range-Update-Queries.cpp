/**
 *    author:  MaGnsi0
 *    created: 14/07/2021 19:39:54
**/
#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    int N;
    vector<long long> A, segTree, lazyPropagation;
    int L(int p) {
        return (p << 1);
    }
    int R(int p) {
        return (p << 1) + 1;
    }
    long long compine(long long a, long long b) {
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
        segTree[p] += (r - l + 1) * lazyPropagation[p];
        if (l != r) {
            lazyPropagation[L(p)] += lazyPropagation[p];
            lazyPropagation[R(p)] += lazyPropagation[p];
        } else {
            A[l] = lazyPropagation[p];
        }
        lazyPropagation[p] = 0;
    }
    long long query(int p, int l, int r, int i, int j) {
        propagate(p, l, r);
        if (i > j) {
            return 0LL;
        }
        if (i <= l && r <= j) {
            return segTree[p];
        }
        int m = (l + r) / 2;
        return compine(query(L(p), l, m, i, min(m, j)), query(R(p), m + 1, r, max(i, m + 1), j));
    }
    void update(int p, int l, int r, long long v, int i, int j) {
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
    segment_tree(int n, vector<long long> a) {
        N = n;
        A = a;
        segTree = vector<long long>(4 * n, 0);
        lazyPropagation = vector<long long>(4 * n, 0);
        build(1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    segment_tree st(n, v);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            long long v;
            cin >> i >> j >> v;
            st.update(1, 0, n - 1, v, i - 1, j - 1);
        } else {
            int k;
            cin >> k;
            cout << st.query(1, 0, n - 1, k - 1, k - 1) << "\n"; 
        }
    }
}