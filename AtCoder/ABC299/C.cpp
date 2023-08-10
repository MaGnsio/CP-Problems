/**
 *    author:  MaGnsi0
 *    created: 22.04.2023 14:08:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if (count(s.begin(), s.end(), '-') == 0) {
        cout << -1;
        return 0;
    }
    if (count(s.begin(), s.end(), 'o') == 0) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (s[i] == 'o') {
            j++;
        } else {
            ans = max(ans, j);
            j = 0;
        }
        if (i == n - 1) {
            ans = max(ans, j);
        }
    }
    cout << ans;
}
