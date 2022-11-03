/**
 *    author:  MaGnsi0
 *    created: 25.09.2022 16:34:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<int> a(10);
        for (int i = 0; i < n; ++i) {
            a[s[i] - '0']++;
        }
        string x = "", y = "";
        for (int i = 0; i < n; ++i) {
            bool have_less = false;
            a[s[i] - '0']--;
            for (int j = 0; j < s[i] - '0'; ++j) {
                have_less |= (a[j] > 0);
            }
            if (have_less) {
                y += min('9', char(s[i] + 1));
            } else {
                x += s[i];
            }
        }
        sort(y.begin(), y.end());
        string ans = "";
        int i = 0, j = 0;
        while (i < (int)x.size() && j < (int)y.size()) {
            if (x[i] < y[j]) {
                ans += x[i++];
            } else {
                ans += y[j++];
            }
        }
        while (i < (int)x.size()) {
            ans += x[i++];
        }
        while (j < (int)y.size()) {
            ans += y[j++];
        }
        cout << ans << "\n";
    }
}
