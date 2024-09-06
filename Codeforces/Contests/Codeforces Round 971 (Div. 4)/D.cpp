/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 00:49:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<set<int>> a(2);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            int y; cin >> y;
            a[y].insert(x);
        }
        int64_t ans = 0;
        for (int x : a[0]) {
            if (a[1].count(x)) {
                ans += n - 2;
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int x : a[i]) {
                ans += a[i ^ 1].count(x - 1) && a[i ^ 1].count(x + 1);
            }
        }
        cout << ans << "\n";
    }
}
