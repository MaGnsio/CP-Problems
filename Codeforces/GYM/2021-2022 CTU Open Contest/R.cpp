/**
 *    author:  MaGnsi0
 *    created: 31.01.2024 21:28:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = (int)s.size(), ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (s[i] == '1') {
            ans = max(ans, (j + 1) / 2);
            j = 0;
        } else {
            j++;
        }
    }
    cout << ans;
}
