/**
 *    author:  MaGnsi0
 *    created: 01.02.2023 21:51:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    vector<bool> a(m, false), b(m, false);
    for (int i = 0; i < m; ++i) { 
        a[i] = (t[i] == s[i]) || (s[i] == '?') || (t[i] == '?');
        if (i) {
            a[i] = a[i] && a[i - 1];
        }
    }
    for (int i = m - 1, j = n - 1; i >= 0; --i, --j) {
        b[i] = (t[i] == s[j]) || (s[j] == '?') || (t[i] == '?');
        if (i < m - 1) {
            b[i] = b[i] && b[i + 1];
        }
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i <= m; ++i) {
        bool x = (i ? a[i - 1] : true);
        bool y = (i < m ? b[m - i - 1] : true);
        cout << (x && y ? "Yes" : "No") << "\n";
    }
}
