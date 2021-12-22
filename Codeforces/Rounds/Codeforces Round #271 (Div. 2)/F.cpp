/**
 *    author:  MaGnsi0
 *    created: 17.12.2021 17:07:04
**/
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    int N;
    vector<int> A, segTree;
    int L(int p) {
        return (p << 1);
    }
    int R(int p) {
        return (p << 1) + 1;
    }
    int compine(int a, int b) {
        return __gcd(a, b);
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
    int query(int p, int l, int r, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i <= l && r <= j) {
            return segTree[p];
        }
        int m = (l + r) / 2;
        return compine(query(L(p), l, m, i, min(m, j)), query(R(p), m + 1, r, max(i, m + 1), j));
    }
    segment_tree(int n, vector<int> a) {
        N = n;
        A = a;
        segTree = vector<int>(4 * n, 0);
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
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    segment_tree st(n, a);
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int x = st.query(1, 0, n - 1, l - 1, r - 1);
        pair<int, int> p = make_pair(x, l - 1);
        int from = lower_bound(b.begin(), b.end(), p) - b.begin();
        p = make_pair(x, r);
        int to = lower_bound(b.begin(), b.end(), p) - b.begin();
        cout << (r - l + 1) - (to - from) << "\n";
    }
}
