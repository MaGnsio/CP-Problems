/**
 *    author:  MaGnsi0
 *    created: 09.03.2022 16:31:13
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
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && s[i + 1] == s[i]) {
                i++;
            }
            ans++;
        }
        cout << ans << "\n";
    }
}
