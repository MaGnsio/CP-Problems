/**
 *    author:  MaGnsi0
 *    created: 22/07/2021 17:22:30
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        string x = "";
        int n = s.size(), m = t.size(), last = n;
        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
            if (s[i] == t[j] && ((last - i) & 1)) {
                x += s[i];
                last = i;
                j--;
            }
        }
        reverse(x.begin(), x.end());
        if (x == t) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
