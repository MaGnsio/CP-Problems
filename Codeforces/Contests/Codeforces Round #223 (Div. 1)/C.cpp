/**
 *    author:  MaGnsi0
 *    created: 15/07/2021 17:51:33
**/
#include <bits/stdc++.h>
using namespace std;

struct T {
    int n, pre, suf;
};

struct segment_tree {
    int N;
    vector<T> A, segTree;
    int L(int p) {
        return (p << 1);
    }
    int R(int p) {
        return (p << 1) + 1;
    }
    T compine(T a, T b) {
        T c;
        c.n = a.n + b.n + min(a.pre, b.suf);
        c.pre = a.pre + b.pre - min(a.pre, b.suf);
        c.suf = a.suf + b.suf - min(a.pre, b.suf);
        return c;
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
    T query(int p, int l, int r, int i, int j) {
        if (i > j) {
            T c = {0, 0, 0};
            return c;
        }
        if (i <= l && r <= j) {
            return segTree[p];
        }
        int m = (l + r) / 2;
        return compine(query(L(p), l, m, i, min(m, j)), query(R(p), m + 1, r, max(i, m + 1), j));
    }
    segment_tree(int n, vector<T> a) {
        N = n;
        A = a;
        segTree = vector<T>(4 * n);
        build(1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int q;
    string s;
    cin >> s >> q;
    vector<T> v(s.size());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            v[i] = {0, 1, 0};
        } else {
            v[i] = {0, 0, 1};
        }
    }
    segment_tree st(s.size(), v);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << 2 * st.query(1, 0, st.N - 1, l - 1, r - 1).n << "\n";
    }
}
