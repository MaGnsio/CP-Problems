/**
 *    author:  MaGnsi0
 *    created: 12/08/2021 22:58:29
**/
#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    int N;
    vector<long long> A, segTree;
    int L(int p) {
        return (p << 1);
    }
    int R(int p) {
        return (p << 1) + 1;
    }
    long long compine(long long a, long long b) {
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
    long long query(int p, int l, int r, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i <= l && r <= j) {
            return segTree[p];
        }
        int m = (l + r) / 2;
        return compine(query(L(p), l, m, i, min(m, j)), query(R(p), m + 1, r, max(i, m + 1), j));
    }
    segment_tree(int n, vector<long long> a) {
        N = n - 1;
        for (int i = 0; i < n - 1; ++i) {
            A.push_back(llabs(a[i] - a[i + 1]));
        }
        segTree = vector<long long>(4 * n, 0);
        build(1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, res = 1;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        segment_tree st(n, v);
        for (int i = 0; i < n - 1; ++i) {
            int l = i, r = n - 2;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (st.query(1, 0, n - 2, i, mid) > 1LL) {
                    res = max(res, mid - i + 2);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        cout << res << "\n";
    }
}
