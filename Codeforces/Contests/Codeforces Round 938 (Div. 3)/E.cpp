/**
 *    author:  MaGnsi0
 *    created: 11.04.2024 19:51:44
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
        for (S[j += N] += x; j /= 2;) {
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
        int n; cin >> n;
        string s; cin >> s;
        for (int k = n; k; --k) {
            segment_tree<int> b(n + 1, 0, [](int x, int y) { return x + y; });
            for (int i = 0; i + k - 1 < n; ++i) {
                if ((s[i] == '0') ^ (b.query(0, i + 1) & 1)) {
                    b.update(i, 1), b.update(i + k, -1);
                }
            }
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                ok = (ok && (s[i] == '0') ^ !(b.query(0, i + 1) & 1));
            }
            if (ok) {
                cout << k << "\n";
                break;
            }
        }
    }
}
