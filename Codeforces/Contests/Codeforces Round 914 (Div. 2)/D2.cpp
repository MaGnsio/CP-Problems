/**
 *    author:  MaGnsi0
 *    created: 19.12.2023 15:06:00
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
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]].push_back(i);
        }
        bool ok = true;
        segment_tree<int> maxa(n, 0, [](int x, int y) { return max(x, y); });
        segment_tree<int> minb(n, INT_MAX, [](int x, int y) { return min(x, y); });
        for (int i = 0; i < n; ++i) {
            maxa.update(i, a[i]);
            minb.update(i, b[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) { continue; }
            if (a[i] > b[i]) {
                ok = false;
                break;
            }
            int high = lower_bound(mp[b[i]].begin(), mp[b[i]].end(), i) - mp[b[i]].begin();
            int low = (high == mp[b[i]].size() ? (mp[b[i]].empty() ? -1 : mp[b[i]].size() - 1) : (high < 1 ? -1 : high - 1));
            if (high == mp[b[i]].size()) { high = -1; }
            if (low != -1) { low = mp[b[i]][low]; }
            if (high != -1) { high = mp[b[i]][high]; }
            bool can = false;
            if (high != -1) {
                can |= (maxa.query(i, high + 1) == b[i]) && (minb.query(i, high + 1) >= b[i]);
            }
            if (low != -1) {
                can |= (maxa.query(low, i + 1) == b[i]) && (minb.query(low, i + 1) >= b[i]);
            }
            ok = ok && can;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
