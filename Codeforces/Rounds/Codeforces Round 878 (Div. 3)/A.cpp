/**
 *    author:  MaGnsi0
 *    created: 07.06.2023 03:52:27
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
        string ans = "";
        for (int i = 0; i < n; ++i) {
            ans += s[i];
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == s[i]) {
                    i = j;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}
