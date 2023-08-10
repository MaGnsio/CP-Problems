/**
 *    author:  MaGnsi0
 *    created: 18.06.2023 11:14:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        function<int(bool)> solve = [&](bool x) {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += s[i] != t[i];
            }
            if (!x) {
                return (2 * ans) - (ans & 1);
            } else {
                if (ans == 0) {
                    return 2;
                } else if (ans & 1) {
                    return 2 * ans;
                } else {
                    return 2 * ans - 1;
                }
            }
        };
        int ans = solve(0);
        reverse(t.begin(), t.end());
        ans = min(ans, solve(1));
        cout << ans << "\n";
    }
}
