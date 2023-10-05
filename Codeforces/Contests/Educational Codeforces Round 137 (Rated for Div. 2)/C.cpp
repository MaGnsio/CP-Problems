/**
 *    author:  MaGnsi0
 *    created: 17.10.2022 16:43:32
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
        string s;
        cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = (s[0] == '1' ? a[0] : 0), last = (s[0] == '1' ? 0 : a[0]);
        for (int i = 1; i < n; ++i) {
            if (last > a[i] && s[i] == '1') {
                ans += last;
                last = a[i];
            } else if (s[i] == '1') {
                ans += a[i];
            } else {
                last = a[i];
            }
        }
        cout << ans << "\n";
    }
}
