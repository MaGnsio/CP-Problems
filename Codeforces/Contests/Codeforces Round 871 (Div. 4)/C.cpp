/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 16:33:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> a(3);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            string y; cin >> y;
            if (y == "00") { continue; }
            if (y == "11") { a[0].push_back(x); }
            if (y == "10") { a[1].push_back(x); }
            if (y == "01") { a[2].push_back(x); }
        }
        for (int i = 0; i < 3; ++i) {
            sort(a[i].begin(), a[i].end());
        }
        int x = (a[0].empty() ? INT_MAX : a[0][0]);
        int y = (a[1].empty() || a[2].empty() ? INT_MAX : a[1][0] + a[2][0]);
        int ans = min(x, y);
        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }
}
