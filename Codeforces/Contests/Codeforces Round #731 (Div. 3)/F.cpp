/**
 *    author:  MaGnsi0
 *    created: 27/07/2021 05:46:31
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
        return gcd(a, b);
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
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, g = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            g = gcd(g, v[i]);
        }
        for (int i = 0; i < n; ++i) {
            v[i] /= g;
        }
        for (int i = 0; i < n; ++i) {
            v.push_back(v[i]);
        }
        segment_tree st(2 * n, v);
        int l = 1, r = n, res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            bool ok = false;
            for (int i = 0; i <= 2 * n - m; ++i) {
                if (st.query(1, 0, 2 * n - 1, i, i + m - 1) > 1) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << res << "\n";
    }
}
