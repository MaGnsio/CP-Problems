/**
 *    author:  MaGnsi0
 *    created: 06.05.2022 16:34:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int k;
        vector<bool> special(26, false);
        cin >> k;
        for (int i = 0; i < k; ++i) {
            char x;
            cin >> x;
            special[x - 'a'] = true;
        }
        int ans = 0, last_special = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (last_special != -1) {
                ans = max(ans, last_special - i);
            }
            if (special[s[i] - 'a']) {
                last_special = i;
            }
        }
        cout << ans << "\n";
    }
}
