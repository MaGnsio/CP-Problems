/**
 *    author:  MaGnsi0
 *    created: 01.10.2022 15:05:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int64_t>> a(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = make_tuple(u - 1, v - 1, w);
    }
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    vector<set<int64_t>> d(n);
    for (int i = 0; i < k; ++i) {
        int j = b[i] - 1;
        if (get<0>(a[j]) == 0) {
            d[get<1>(a[j])].insert(get<2>(a[j]));
        } else {
            if (d[get<0>(a[j])].empty()) { continue; }
            d[get<1>(a[j])].insert(*d[get<0>(a[j])].begin() + get<2>(a[j]));
        }
    }
    if (d[n - 1].empty()) {
        cout << -1;
    } else {
        cout << *d[n - 1].begin();
    }
}
