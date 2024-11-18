/**
 *    author:  MaGnsi0
 *    created: 18.11.2024 19:08:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> f(20);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; f[x - 1]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += f[i] / 2;
        }
        cout << ans << "\n";
    }
}
