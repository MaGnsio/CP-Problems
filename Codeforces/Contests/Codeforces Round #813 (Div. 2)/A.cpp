/**
 *    author:  MaGnsi0
 *    created: 13.08.2022 16:32:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i].second > k;
        }
        cout << ans << "\n";
    }
}
