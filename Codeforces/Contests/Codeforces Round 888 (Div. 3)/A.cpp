/**
 *    author:  MaGnsi0
 *    created: 25.07.2023 17:36:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k, h;
        cin >> n >> m >> k >> h;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (abs(h - x) % k == 0 && abs(h - x) / k < m && h != x) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
