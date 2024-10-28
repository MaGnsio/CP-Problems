/**
 *    author:  MaGnsi0
 *    created: 28.10.2024 18:02:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        string s; cin >> s;
        int64_t ans = n * (n + 1) / 2;
        set<int> buy_days, to_buy;
        for (int i = n - 1, j = n, need = 0; i >= 0; --i) {
            if (j < 2) { break; }
            if (s[i] == '1') {
                ans -= (i + 1);
                j -= 2; need++;
            } else {
                if (need) {
                    need--; 
                } else {
                    j--;
                }
            }
        }
        cout << ans << "\n";
    }
}
