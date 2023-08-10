/**
 *    author:  MaGnsi0
 *    created: 25.05.2023 17:40:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 2;
        for (int i = 1, j = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                ans = max(ans, j + 1);
                j = 1;
            } else {
                j++;
            }
            if (i == n - 1) {
                ans = max(ans, j + 1);
            }
        }
        cout << ans << "\n";
    }
}
