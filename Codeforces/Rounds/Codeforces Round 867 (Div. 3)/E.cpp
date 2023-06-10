/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 17:15:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        if (n & 1) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> f(26, 0);
        for (int i = 0; i < n; ++i) {
            f[s[i] - 'a']++;
        }
        bool bad = false;
        for (int i = 0; i < 26; ++i) {
            bad |= f[i] > n / 2;
        }
        if (bad) {
            cout << -1 << "\n";
            continue;
        }
        fill(f.begin(), f.end(), 0);
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == s[n - i - 1]) {
                f[s[i] - 'a']++;
            }
        }
        int ans = (accumulate(f.begin(), f.end(), 0) + 1) / 2;
        ans = max(ans, *max_element(f.begin(), f.end()));
        cout << ans << "\n";
    }
}
