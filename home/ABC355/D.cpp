/**
 *    author:  MaGnsi0
 *    created: 25.05.2024 15:20:42
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

void compress(vector<pair<int, int>>& a) {
    int n = (int)a.size();
    set<int> S;
    for (auto [x, y] : a) {
        S.insert(x);
        S.insert(y);
    }
    map<int, int> mp;
    for (int x : S) { mp[x] = (int)mp.size(); }
    for (auto& [x, y] : a) {
        x = mp[x], y = mp[y];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    compress(a);
    segment_tree<int> b(2 * n, 0, [](int x, int y) { return x + y; });
    for (int i = 0; i < n; ++i) {
        b.update(a[i].first, 1);
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        b.update(a[i].first, -1);
        ans += b.query(a[i].first, a[i].second + 1);
    }
    cout << ans;
}
