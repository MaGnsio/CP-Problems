/**
 *    author:  MaGnsi0
 *    created: 08.02.2023 10:13:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size(), l = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            ans = max(ans, i - l);
            l = i;
        }
    }
    ans = max(ans, n - l);
    cout << ans;
}
