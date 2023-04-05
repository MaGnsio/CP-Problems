/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 09:29:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int m = (l + r) / 2;
        bool ok = false;
        for (int i = 0; i < 26; ++i) {
            vector<int> a(n);
            for (int j = 0; j < n; ++j) {
                a[j] = s[j] - 'a' == i;
            }
            for (int j = 1; j < n; ++j) {
                a[j] += a[j - 1];
            }
            for (int j = m - 1; j < n; ++j) {
                ok |= (m - (a[j] - (j - m >= 0 ? a[j - m] : 0))) <= k;
            }
        }
        if (ok) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans;
}
