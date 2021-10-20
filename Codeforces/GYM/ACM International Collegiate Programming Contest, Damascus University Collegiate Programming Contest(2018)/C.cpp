/**
 *    author:  MaGnsi0
 *    created: 05/08/2021 05:17:09
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        bool ok = true;
        int n = s.size(), cnt = 0, cur = 0;
        for (int i = 0; i < n / 2; ++i) {
            char a = (cur ? s[n - 1 - i] : s[i]);
            if (a != t[i]) {
                cur ^= 1;
                cnt++;
                char b = (cur ? s[n - 1 - i] : s[i]);
                if (b != t[i]) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok && s[n / 2] == t[n / 2] ? cnt : -1) << "\n";
    }
}
