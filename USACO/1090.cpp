/**
 *    author:  MaGnsi0
 *    created: 01.08.2024 20:34:29
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    vector<int64_t> b(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            char c; cin >> c;
            if (c == '1') {
                b[i] |= 1LL << j;
            }
        }
    }
    vector<set<int>> cp(k);
    vector<set<int>> cn(k);
    for (int i = 0; i < n; ++i) {
        cp[a[i]].insert(i);
        cn[a[i]].insert(-i);
    }
    vector<vector<pair<int, int64_t>>> adj(n);
    for (int i = 0; i < n; ++i) {
        int c = a[i];
        for (int j = 0; j < k; ++j) {
            auto it1 = cp[j].upper_bound(i);
            if (it1 != cp[j].end()) {
                adj[i].emplace_back(*it1, abs(i - *it1));
                adj[*it1].emplace_back(i, abs(i - *it1));
            }
            auto it2 = cn[j].upper_bound(-i);
            if (it2 != cn[j].end()) {
                adj[i].emplace_back(-*it2, abs(i + *it2));
                adj[-*it2].emplace_back(i, abs(i + *it2));
            }
        }
    }
    set<tuple<int64_t, int64_t, int>> S;
    vector<int64_t> ans(n, OO);
    S.emplace(0, b[a[0]], 0), ans[0] = 0;
    while (!S.empty()) {
        auto [d, allowed, v] = *S.begin();
        S.erase(S.begin());
        for (auto [u, d] : adj[v]) {
            if (!(allowed >> a[u] & 1)) { continue; }
            if (ans[v] + d < ans[u]) {
                ans[u] = ans[v] + d;
                S.emplace(ans[u], allowed | b[a[u]], u);
            }
        }
    }
    cout << (ans[n - 1] == OO ? -1 : ans[n - 1]);
}
