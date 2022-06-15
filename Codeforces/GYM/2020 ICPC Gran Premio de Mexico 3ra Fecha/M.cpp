/**
 *    author:  MaGnsi0
 *    created: 12.05.2022 21:31:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size(), m = 10;
    vector<int> a(m), b(m, 0);
    for (int i = 1; i < m; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        b[s[i] - '0']++;
    }
    int x = n - accumulate(a.begin(), a.end(), 0);
    string ans = "";
    for (int i = 0, l = 0; i < x; ++i) {
        for (int j = 9; j >= 1; --j) {
            int can_l = -1;
            vector<int> c(m, 0);
            for (int k = l; k < n; ++k) {
                if (s[k] - '0' == j && b[j] > a[j]) {
                    can_l = k;
                    break;
                }
                c[s[k] - '0']++;
            }
            bool ok = true;
            for (int k = 1; k < m; ++k) {
                if (c[k] > a[k]) {
                    ok = false;
                }
            }
            if (can_l != -1 && ok) {
                for (int k = 1; k < m; ++k) {
                    a[k] -= c[k];
                    b[k] -= c[k];
                }
                ans += s[can_l];
                l = can_l + 1;
                b[j]--;
                break;
            }
        }
        if (i == x - 1) {
            for (int j = l; j < n; ++j) {
                a[s[j] - '0']--;
            }
        }
    }
    assert(accumulate(a.begin(), a.end(), 0) == 0);
    cout << ans;
}
