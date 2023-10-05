/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 16:32:02
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
        return min(a, b);
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
            return INT_MAX;
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
        segTree = vector<int>(4 * n, INT_MAX);
        build(1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), x(2 * n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            x[a[i]] = x[a[i] + 1] = i;
        }
        segment_tree st(2 * n + 1, x);
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            ans = min(ans, i + st.query(1, 0, 2 * n, 1, b[i]));
        }
        cout << ans << "\n";
    }
}
