/**
 *    author:  MaGnsi0
 *    created: 10.07.2022 16:32:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t p;
        string s;
        cin >> s >> p;
        int64_t sum = 0;
        vector<int> f(26, 0);
        for (int i = 0; i < (int)s.size(); ++i) {
            f[s[i] - 'a']++;
            sum += (s[i] - 'a' + 1);
        }
        for (int i = 25; i >= 0; --i) {
            if (sum <= p) {
                break;
            }
            while (sum > p && f[i]) {
                sum -= (i + 1);
                f[i]--;
            }
        }
        string ans = "";
        vector<int> nf(26, 0);
        for (int i = 0; i < (int)s.size(); ++i) {
            if (nf[s[i] - 'a'] < f[s[i] - 'a']) {
                ans += s[i];
                nf[s[i] - 'a']++;
            }
        }
        cout << ans << "\n";
    }
}
