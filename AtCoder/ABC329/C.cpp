/**
 *    author:  MaGnsi0
 *    created: 18.11.2023 14:03:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<int> F(26, 0);
    for (int i = 1, x = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            F[s[i - 1] - 'a'] = max(F[s[i - 1] - 'a'], x);
            x = 1;
        } else {
            x++;
        }
        if (i == n - 1) {
            F[s[i] - 'a'] = max(F[s[i] - 'a'], x);
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans += F[i];
    }
    cout << ans;
}
