/**
 *    author:  MaGnsi0
 *    created: 02.03.2023 20:48:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n - 1;
        for (int i = 0; i + 2 < n; ++i) {
            ans -= s[i] == s[i + 2];
        }
        cout << ans << "\n";
    }
}
