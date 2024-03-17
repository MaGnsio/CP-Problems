/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 22:21:36
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int> b(n, 1, [](int x, int y) { return x & y; });
    for (int i = 0; i < n; ++i) {
        b.update(i, 0);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] < n) {
            b.update(a[i], 1);
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]]++;
    }
    while (Q--) {
        int j; cin >> j; j--;
        int x; cin >> x;
        mp[a[j]]--;
        if (a[j] < n && mp[a[j]] == 0) {
            b.update(a[j], 0);
        }
        a[j] = x;
        mp[a[j]]++;
        if (a[j] < n) {
            b.update(a[j], 1);
        }
        int low = 0, high = n - 1, mex = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (b.query(0, mid + 1) == 0) {
                mex = mid, high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << mex << "\n";
    }
}
