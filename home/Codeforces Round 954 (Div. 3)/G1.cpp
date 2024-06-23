/**
 *    author:  MaGnsi0
 *    created: 23.06.2024 19:15:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t ans = 0;
        map<int, map<int, int>> mp;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            int b = i + 1;
            int x = __gcd(a, b);
            a /= x, b /= x;
            for (int j = 1; j * j <= a; ++j) {
                if (a % j == 0) {
                    ans += mp[b][j];
                    if (a != j * j) {
                        ans += mp[b][a / j];
                    }
                }
            }
            for (int j = 1; j * j <= a; ++j) {
                if (a % j == 0) {
                    mp[j][b]++;
                    if (a != j * j) {
                        mp[a / j][b]++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
