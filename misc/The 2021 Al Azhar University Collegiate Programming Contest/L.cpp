#include "bits/stdc++.h"
using namespace std;

struct node {
    int mx_inc, mx_dec;
    int mxp_inc, mxp_dec;
    int mxs_inc, mxs_dec;
    int len, f, l;
};

node O = {1, 1, 1, 1, 1, 1, 1};
node zero = {0, 0, 0, 0, 0, 0, 0, 0, 0};

struct segment_tree {
    int N;
    vector<int> A, lp;
    vector<node> st;
    int L(int p) {
        return (p << 1);
    }
    int R(int p) {
        return (p << 1) + 1;
    }
    node compine(node a, node b) {
        node ret;
        ret.mx_inc = max(a.mx_inc, b.mx_inc);
        if (a.l <= b.f) {
            ret.mx_inc = max(ret.mx_inc, a.mxs_inc + b.mxp_inc);
        }
        ret.mx_dec = max(a.mx_dec, b.mx_dec);
        if (a.l >= b.f) {
            ret.mx_dec = max(ret.mx_dec, a.mxs_dec + b.mxp_dec);
        }
        ret.mxp_inc = a.mxp_inc;
        if (a.mxp_inc == a.len && a.l <= b.f) {
            ret.mxp_inc += b.mxp_inc;
        }
        ret.mxp_dec = a.mxp_dec;
        if (a.mxp_dec == a.len && a.l >= b.f) {
            ret.mxp_dec += b.mxp_dec;
        }
        ret.mxs_inc = b.mxs_inc;
        if (b.mxs_inc == b.len && a.l <= b.f) {
            ret.mxs_inc += a.mxs_inc;
        }
        ret.mxs_dec = b.mxs_dec;
        if (b.mxs_dec == b.len && a.l >= b.f) {
            ret.mxs_dec += a.mxp_dec;
        }
        ret.len = a.len + b.len;
        ret.f = a.f;
        ret.l = b.l;
        return ret;
    }
    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = O;
            st[p].f = st[p].l = A[l];
            return;
        } else {
            int m = (l + r) / 2;
            build(L(p), l, m);
            build(R(p), m + 1, r);
            st[p] = compine(st[L(p)], st[R(p)]);
        }
    }
    void flip(node& a) {
        swap(a.mx_inc, a.mx_dec);
        swap(a.mxp_inc, a.mxp_dec);
        swap(a.mxs_inc, a.mxs_dec);
        a.f ^= 1;
        a.l ^= 1;
    }
    void propagate(int p, int l,int r) {
        if (lp[p] == 0) {
            return;
        }
        flip(st[p]);
        if (l != r) {
            lp[L(p)] ^= lp[p];
            lp[R(p)] ^= lp[p];
        } else {
            A[l] ^= lp[p];
        }
        lp[p] = 0;
    }
    node query(int p, int l, int r, int i, int j) {
        propagate(p, l, r);
        if (i > j) {
          return zero;
        }
        if (i <= l && r <= j) {
            return st[p];
        }
        int m = (l + r) / 2;
        return compine(query(L(p), l, m, i, min(m, j)), query(R(p), m + 1, r, max(i,m + 1), j));
    }
    void update(int p, int l, int r, int v, int i, int j) {
        propagate(p, l, r);
        if (i > j) {
            return;
        }
        if (i <= l && r <= j) {
            lp[p] = v;
            propagate(p, l, r);
        } else {
            int m = (l + r) / 2;
            update(L(p), l, m, v, i, min(m, j));
            update(R(p), m + 1, r, v, max(i, m + 1), j);
            propagate(L(p), l, m);
            propagate(R(p), m + 1, r);
            st[p] = compine(st[L(p)], st[R(p)]);
        }
    }
    segment_tree(int n, vector<int> a) {
        N = n;
        A = a;
        st = vector<node>(4 * n, zero);
        lp = vector<int>(4 * n, 0);
        build(1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        string s;
        cin >> n >> q >> s;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = (s[i] - '0');
        }
        segment_tree k(n, v);
        for (int i = 0; i < q; ++i) {
            int t, l, r;
            cin >> t >> l >> r;
            l--, r--;
            if (t == 1) {
                k.update(1, 0, n - 1, 1, l, r);
            } else if (t == 2) {
                cout << k.query(1, 0, n - 1, l, r).mx_inc << "\n";
            } else {
                cout << k.query(1, 0, n - 1, l, r).mx_dec << "\n";
            }
        }
    }
}

/*********
intput:
3
5
4
10101
2 1 5
3 4 5
1 1 5
3 1 2
2 3
00
2 1 2
1 1 1
2 1 2
10 2
0000111101
2 1 9
3 5 10
output:
2
1
1
2
1
8
5
*********/
