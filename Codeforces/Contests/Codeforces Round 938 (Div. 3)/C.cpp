/**
 *    author:  MaGnsi0
 *    created: 11.04.2024 18:28:33
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
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t k; cin >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int low = 0, high = n - 1;
        while (low <= high && k) {
            if (low == high) {
                a[low] -= k;
                a[low] = max(a[low], 0LL);
                break;
            }
            if (a[low] <= a[high]) {
                int64_t need = 2 * a[low] - 1;
                if (need > k) { break; }
                k -= need;
                a[high] -= a[low] - (k == 0);
                a[low] = 0;
                if (k == 0) { break; }
                k--, low++;
            } else {
                int64_t need = 2 * a[high];
                if (need > k) { break; }
                k -= need;
                a[low] -= a[high];
                a[high] = 0;
                high--;
            }
        }
        int ans = count(a.begin(), a.end(), 0);
        cout << ans << "\n";
    }
}
