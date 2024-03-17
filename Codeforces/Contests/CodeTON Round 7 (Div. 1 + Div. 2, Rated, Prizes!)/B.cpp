/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 16:53:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s;  cin >> s;
        int ans = n - 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') { break; }
            ans--;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'B') { break; }
            ans--;
        }
        cout << max(ans, 0) << "\n";
    }
}
