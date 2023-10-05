/**
 *    author:  MaGnsi0
 *    created: 10.01.2022 16:35:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> f(26, 0);
        for (int i = 0; i < n; ++i) {
            f[s[i] - 'a']++;
        }
        int x = 0, y = 0;
        for (int i = 0; i < 26; ++i) {
            x += (f[i] / 2);
            f[i] -= 2 * (f[i] / 2);
            y += f[i];

        }
        if (k == 1) {
            cout << 2 * x + (y != 0) << "\n";
        } else {
            int res = 2 * (x / k);
            res += ((2 * (x % k) + y >= k) ? 1 : 0);
            cout << res << "\n";
        }
    }
}
