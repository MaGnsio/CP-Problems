/**
 *    author:  MaGnsi0
 *    created: 27.03.2022 16:27:08
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
        int ans = 0;
        for (int i = 0; i + 1 < (int)s.size(); ++i) {
            if (s[i] == '0' && s[i + 1] == '0') {
                ans += 2;
            } else if (i + 2 < n && s[i] == '0' && s[i + 2] == '0') {
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
}
