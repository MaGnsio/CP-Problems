/**
 *    author:  MaGnsi0
 *    created: 17.09.2023 15:05:22
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] + (a[i] > a[i - 1]);
    }
    bool ok = false;
    for (int i = k - 1; i < n; ++i) {
        ok |= b[i] - b[i - k + 1] == k - 1;
    }
    if (!ok) {
        segment_tree<int> s(n, n + 1, [](int x, int y) { return min(x, y); });
        for (int i = 0; i < n; ++i) {
            s.update(i, a[i]);
        }
        int j = n - k;
        for (int i = n - k - 1; (n - k - i) < k && i >= 0; --i) {
            int L1 = i, R1 = n - k - 1;
            if (b[R1] - b[L1] == R1 - L1 && a[R1] < s.query(R1 + 1, R1 + k - (R1 - L1))) {
                j = i;
            }
        }
        sort(a.begin() + j, a.begin() + j + k);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
