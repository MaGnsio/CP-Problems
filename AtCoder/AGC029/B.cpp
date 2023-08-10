/**
 *    author:  MaGnsi0
 *    created: 23.06.2023 17:00:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    map<int64_t, set<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].insert(i);
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        if (mp[a[i]].count(i) == 0) {
            continue;
        }
        mp[a[i]].erase(i);
        for (int j = 32; j >= 0; --j) {
            int64_t x = (1LL << j) - a[i];
            if (mp.count(x) && !mp[x].empty()) {
                mp[x].erase(mp[x].begin());
                ans++;
                break;
            }
        }
    }
    cout << ans;
}
