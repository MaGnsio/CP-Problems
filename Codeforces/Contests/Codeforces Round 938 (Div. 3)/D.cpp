/**
 *    author:  MaGnsi0
 *    created: 11.04.2024 18:55:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> b, c;
        for (int i = 0; i < m; ++i) {
            int x; cin >> x; b[x]++;
        }
        int have = 0;
        for (int i = 0; i < m; ++i) {
            have += c[a[i]] < b[a[i]];
            c[a[i]]++;
        }
        int ans = have >= k;
        for (int i = m; i < n; ++i) {
            have -= c[a[i - m]] <= b[a[i - m]];
            c[a[i - m]]--;
            have += c[a[i]] < b[a[i]];
            c[a[i]]++;
            ans += have >= k;
        }
        cout << ans << "\n";
    }
}
