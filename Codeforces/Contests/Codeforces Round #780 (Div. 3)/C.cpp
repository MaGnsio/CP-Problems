/**
 *    author:  MaGnsi0
 *    created: 31.03.2022 17:46:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = 0;
        vector<int> f(26, 0);
        for (int i = 0; i < (int)s.size(); ++i) {
            f[s[i] - 'a']++;
            if (f[s[i] - 'a'] == 2) {
                ans += accumulate(f.begin(), f.end(), 0) - 2;
                f = vector<int>(26, 0);
            }
        }
        ans += accumulate(f.begin(), f.end(), 0);
        cout << ans << "\n";
    }
}
