/**
 *    author:  MaGnsi0
 *    created: 22.04.2022 09:57:31
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
        map<char, int64_t> F, L;
        map<string, int64_t> mp;
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            ans += (F[s[0]] + L[s[1]] - 2 * mp[s]);
            F[s[0]]++, L[s[1]]++, mp[s]++;
        }
        cout << ans << "\n";
    }
}
