/**
 *    author:  MaGnsi0
 *    created: 09.06.2023 19:31:37
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    set<int64_t> s;
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
        s.insert(b[i]);
        s.insert(a[i] - 1);
    }
    map<int64_t, int64_t> mp1, mp2;
    for (int64_t x : s) {
        mp1[x] = (int)mp1.size() + 1;
        mp2[mp1[x]] = x;
    }
    int m = (int)mp1.size() + 1;
    function<pair<bool, vector<int64_t>>(int)> F = [&](int x) {
        vector<tuple<int, int, int64_t>> edges;
        for (int i = 0; i < m; ++i) {
            edges.emplace_back(m, i, 0);
        }
        for (int i = 1; i < m; ++i) {
            edges.emplace_back(i, i - 1, 0);
            edges.emplace_back(i - 1, i, 1);
        }
        for (int i = 0; i < n; ++i) {
            edges.emplace_back(mp1[a[i] - 1], mp1[b[i]], x);
            edges.emplace_back(mp1[b[i]], mp1[a[i] - 1], -1);
        }
        bool negative;
        vector<int64_t> ans(m + 1, OO);
        ans[m] = 0;
        for (int i = 0; i <= m + 1; ++i) {
            negative = false;
            for (auto [u, v, w] : edges) {
                if (ans[u] + w < ans[v]) {
                    ans[v] = ans[u] + w;
                    negative = true;
                }
            }
        }
        return make_pair(!negative, ans);
    };
    int low = 1, high = n;
    vector<int64_t> ans;
    while (low <= high) {
        int mid = (low + high) / 2;
        pair<bool, vector<int64_t>> ok = F(mid);
        if (ok.first) {
            ans = ok.second;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    int k = 0;
    for (int i = 1; i < m; ++i) {
        k += ans[i] - ans[i - 1];
    }
    cout << k << "\n";
    for (int i = 1; i < m; ++i) {
        if (ans[i] - ans[i - 1]) {
            cout << mp2[i] << " ";
        }
    }
}
