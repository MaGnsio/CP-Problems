/**
 *    author:  MaGnsi0
 *    created: 22.06.2023 11:41:12
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[a[i]] = i;
    }
    segment_tree<int> c(n, 1, [&](int x, int y) { return x & y; });
    for (int i = 1; i < n; ++i) {
        c.update(i, b[i] > b[i - 1]);
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        int low1 = 0, high1 = i, ans1 = 0;
        while (low1 <= high1) {
            int mid1 = (low1 + high1) / 2;
            if (c.query(mid1, i + 1) == 0) {
                ans1 = mid1;
                low1 = mid1 + 1;
            } else {
                high1 = mid1 - 1;
            }
        }
        int low2 = i + 1, high2 = n - 1, ans2 = n;
        while (low2 <= high2) {
            int mid2 = (low2 + high2) / 2;
            if (c.query(i, mid2 + 1) == 0) {
                ans2 = mid2;
                high2 = mid2 - 1;
            } else {
                low2 = mid2 + 1;
            }
        }
        ans = min(ans, ans1 + (n - 1 - ans2 + 1));
    }
    cout << ans;
}
