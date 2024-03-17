/**
 *    author:  MaGnsi0
 *    created: 13.02.2024 16:48:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string ans = "";
        for (int i = 1; i <= 26; ++i) {
            for (int j = 1; j <= 26; ++j) {
                for (int k = 1; k <= 26; ++k) {
                    if (i + j + k == n) {
                        ans += char('a' + i - 1);
                        ans += char('a' + j - 1);
                        ans += char('a' + k - 1);
                        goto done;
                    }
                }
            }
        }
        done:
        cout << ans << "\n";
    }
}
