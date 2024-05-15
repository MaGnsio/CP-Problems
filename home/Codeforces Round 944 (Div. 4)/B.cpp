/**
 *    author:  MaGnsi0
 *    created: 15.05.2024 19:29:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string ans = s;
        sort(ans.begin(), ans.end());
        if (ans == s) {
            sort(ans.rbegin(), ans.rend());
        }
        if (ans == s) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << ans << "\n";
        }
    }
}
