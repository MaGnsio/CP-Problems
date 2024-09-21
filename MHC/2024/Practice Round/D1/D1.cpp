/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 20:10:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        int g; cin >> g;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        pair<int, int> ans = {INT_MAX, n};
        for (int i = 0; i < n; ++i) {
            ans = min(ans, {abs(g - a[i]), i + 1});
        }
        cout << ans.second << " " << ans.first << "\n";
    }
}
