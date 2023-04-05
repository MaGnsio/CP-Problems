/**
 *    author:  MaGnsi0
 *    created: 11.11.2022 18:32:00
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
    for (int i = 0; i < n; ++i) {
        a[i] = (i & 1 ? -1 : 1) * a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int64_t ans = 0;
    map<int64_t, int64_t> mp;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        ans += mp[a[i]];
        mp[a[i]]++;
    }
    cout << ans;
}
