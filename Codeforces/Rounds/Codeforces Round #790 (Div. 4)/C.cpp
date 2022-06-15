/**
 *    author:  MaGnsi0
 *    created: 11.05.2022 15:58:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < m; ++k) {
                    cnt += int(abs(a[i][k] - a[j][k]));
                }
                ans = min(ans, cnt);
            }
        }
        cout << ans << "\n";
    }
}
