/**
 *    author:  MaGnsi0
 *    created: 27.09.2023 17:31:38
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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        segment_tree<int> b(n, (1LL << 31) - 1, [](int x, int y) { return x & y; });
        for (int i = 0; i < n; ++i) {
            b.update(i, a[i]);
        }
        int Q;
        cin >> Q;
        while (Q--) {
            int l, k;
            cin >> l >> k;
            int low = l - 1, high = n - 1, r = -2;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (b.query(l - 1, mid + 1) >= k) {
                    r = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            cout << r + 1 << " ";
        }
        cout << "\n";
    }
}
