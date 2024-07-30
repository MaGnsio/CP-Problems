/**
 *    author:  MaGnsi0
 *    created: 30.07.2024 17:47:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int open = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '_') {
                if (open) {
                    s[i] = ')';
                } else {
                    s[i] = '(';
                }
            }
            open += s[i] == '(';
            open -= s[i] == ')';
        }
        int64_t ans = 0;
        for (int64_t i = 0; i < n; ++i) {
            ans += (s[i] == ')' ? 1 : -1) * i;
        }
        cout << ans << "\n";
    }
}
