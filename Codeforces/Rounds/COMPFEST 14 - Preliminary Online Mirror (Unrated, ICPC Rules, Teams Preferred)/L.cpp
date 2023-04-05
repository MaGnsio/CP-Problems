/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 22:11:54
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
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int64_t maxp = *max_element(a.begin(), a.end());
    int64_t minp = *min_element(a.begin(), a.end());
    if (a[n - 1] != maxp || minp < 0) {
        cout << -1;
        return 0;
    }
    set<int64_t> s(a.begin(), a.end());
    map<int64_t, int> mp;
    for (auto& x : s) {
        mp[x] = mp.size();
    }
    int m = (int)mp.size();
    int64_t ans = 0;
    segment_tree<int> st(m, 0, [](int x, int y) { return x + y; });
    for (int i = 0; i < n; ++i) {
        ans += st.query(mp[a[i]] + 1, m);
        st.update(mp[a[i]], 1);
    }
    cout << ans;
}
