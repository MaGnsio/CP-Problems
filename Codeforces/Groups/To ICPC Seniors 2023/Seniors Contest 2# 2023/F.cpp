/**
 *    author:  MaGnsi0
 *    created: 06.02.2023 16:54:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), I(n);
    iota(I.begin(), I.end(), 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(I.begin(), I.end(), [&](int i, int j) {
            return make_pair(a[i], b[i]) > make_pair(a[j], b[j]);
        });
    int m;
    cin >> m;
    vector<int> w(m), p(m), J(m);
    iota(J.begin(), J.end(), 0);
    for (int i = 0; i < m; ++i) {
        cin >> w[i] >> p[i];
    }
    sort(J.begin(), J.end(), [&](int i, int j) {
            return make_pair(w[i], p[i]) > make_pair(w[j], p[j]);
        });
    vector<int> ans(n);
    set<pair<int, int>> usable;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < m && a[I[i]] <= w[J[j]]) {
            usable.emplace(p[J[j]], J[j]);
            j++;
        }
        auto it = usable.lower_bound(make_pair(b[I[i]], -1));
        if (it == usable.end()) {
            cout << -1;
            return 0;
        } else {
            ans[I[i]] = (it -> second) + 1;
            usable.erase(it);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
