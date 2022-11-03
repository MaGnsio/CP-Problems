/**
 *    author:  MaGnsi0
 *    created: 16.10.2022 23:12:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> b(2);
        for (int i = 0; i < n; ++i) {
            b[a[i]].push_back(i);
        }
        reverse(b[1].begin(), b[1].end());
        int ans = 0;
        while (!b[0].empty() && !b[1].empty() && b[0].back() > b[1].back()) {
            b[0].pop_back();
            b[1].pop_back();
            ans++;
        }
        cout << ans << "\n";
    }
}
