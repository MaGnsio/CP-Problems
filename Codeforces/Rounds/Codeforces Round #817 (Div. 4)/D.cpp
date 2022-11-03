/**
 *    author:  MaGnsi0
 *    created: 30.08.2022 16:34:14
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
        int64_t ans = 0;
        vector<int64_t> changes(n);
        for (int i = 0; i < n; ++i) {
            ans += (s[i] == 'L' ? i : n - i - 1);
            changes[i] = (s[i] == 'R' ? i : n - i - 1) - (s[i] == 'L' ? i : n - i - 1);
        }
        sort(changes.begin(), changes.end(), greater<int64_t>());
        for (int i = 0; i < n; ++i) {
            ans = max(ans, ans + changes[i]);
            cout << ans << " ";
        }
        cout << "\n";
    }
}
