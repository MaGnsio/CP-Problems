/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 20:43:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cat.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < 25; ++i) {
            if ((1LL << i) <= n) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
