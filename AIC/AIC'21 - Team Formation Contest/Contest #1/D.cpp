/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:41
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    map<int, int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }
    int m;
    cin >> m;
    using pii = pair<int, int>;
    vector<pair<pii, int>> f(m, {{0, 0}, 0});
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        f[i].first.first = v[x];
        f[i].second = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        f[i].first.second = v[x];
        f[i].second = i + 1;
    }
    sort(f.begin(), f.end(), greater<pair<pii, int>>());
    cout << f[0].second;
}
