/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 16:46:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        string ans = "";
        for (int i = 0; i < n; ++i) {
            for (char c = 'a'; c < char('a' + k); ++c) {
                ans += c;
            }
        }
        cout << ans << "\n";
    }
}
