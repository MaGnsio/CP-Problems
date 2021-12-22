/**
 *    author:  MaGnsi0
 *    created: 12.11.2021 20:12:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, res = -1;
        cin >> n;
        string s;
        cin >> s;
        for (int i = min(n, 7); i >= 2; --i) {
            int f[3] = {};
            for (int j = 0; j < i; ++j) {
                f[s[j] - 'a']++;
            }
            if (f[0] > f[1] && f[0] > f[2]) {
                res = i;
            }
            for (int j = i; j < n; ++j) {
                f[s[j - i] - 'a']--, f[s[j] - 'a']++;
                if (f[0] > f[1] && f[0] > f[2]) {
                    res = i;
                }
            }
            
        }
        cout << res << "\n";
    }
}
