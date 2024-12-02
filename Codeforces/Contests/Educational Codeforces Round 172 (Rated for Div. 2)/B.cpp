/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 16:41:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> f(n, 0);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; f[x - 1]++;
        }
        int fo = 0, fm = 0;
        for (int i = 0; i < n; ++i) {
            fo += f[i] == 1;
            fm += f[i] > 1;
        }
        int ans = fm + 2 * ((fo + 1) / 2);
        cout << ans << "\n";
    }
}
