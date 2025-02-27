/**
 *    author:  MaGnsi0
 *    created: 27.02.2025 16:42:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        int64_t k; cin >> k;
        string s; cin >> s;
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            x += (s[i] == 'L' ? -1 : +1);
            if (x == 0) {
                ans = 1; k -= (i + 1);
                break;
            }
        }
        if (x) {
            cout << 0 << "\n";
            continue;
        }
        int64_t need = 0;
        for (int i = 0; i < n; ++i) {
            x += (s[i] == 'L' ? -1 : +1);
            if (x == 0) {
                need = i + 1;
                break;
            }
        }
        ans += need ? k / need : 0;
        cout << ans << "\n";
    }
}
