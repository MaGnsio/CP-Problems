/**
 *    author:  MaGnsi0
 *    created: 14.01.2025 20:20:38
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s) {
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; ++i) {
        if(i < r) { z[i] = min(r - i, z[i - l]); }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) { z[i]++; }
        if(i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size();
        vector<int> not_a(n, n);
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'a') {
                not_a[i] = (i + 1 < n ? not_a[i + 1] : n);
            } else {
                not_a[i] = i;
            }
        }
        int start = not_a[0];
        if (start == n) {
            cout << n - 1 << "\n";
            continue;
        }
        int64_t ans = 0;
        string s_ = s.substr(start);
        vector<int> z = z_function(s_);
        for (int m = 1; start + m - 1 < n; ++m) {
            bool good = true;
            int stretch = start, j = start + m;
            while (j < n) {
                int j_ = not_a[j];
                if (j_ == n) { break; }
                if (z[j_ - start] < m) {
                    good = false;
                    break;
                }
                stretch = min(stretch, j_ - j);
                j = j_ + m;
            }
            ans += good * (stretch + 1);
        }
        cout << ans << "\n";
    }
}
