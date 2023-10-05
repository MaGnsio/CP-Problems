/**
 *    author:  MaGnsi0
 *    created: 02.03.2023 20:39:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(s.rbegin(), s.rend());
        vector<int> a(26, 0), b(26, 0);
        for (int i = 0; i < n; ++i) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                a[s[i] - 'A']++;
            } else {
                b[s[i] - 'a']++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            int x = min(a[i], b[i]);
            a[i] -= x;
            b[i] -= x;
            ans += x;
            int y = min(k, max(a[i], b[i]) / 2);
            k -= y;
            ans += y;
        }
        cout << ans << "\n";
    }
}
