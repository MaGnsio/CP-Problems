/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 17:37:37
**/
#include <bits/stdc++.h>

using namespace std;

const string s = "aeiou";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string ans = "";
        for (int i = 0; i < 5; ++i) {
            for (int f = 0; f < (n / 5) + ((n % 5) > i); ++f) {
                ans += s[i];
            }
        }
        cout << ans << "\n";
    }
}
