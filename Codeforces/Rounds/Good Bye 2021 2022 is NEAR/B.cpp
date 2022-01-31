/**
 *    author:  MaGnsi0
 *    created: 29.12.2021 17:20:53
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
        string t = "";
        t += s[0];
        if ((int)s.size() == 1) {
            cout << s << s << "\n";
            continue;
        }
        if (s[0] == s[1]) {
            cout << s[0] << s[0] << "\n";
            continue;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] > s[i - 1]) {
                break;
            }
            t += s[i];
        }
        cout << t;
        reverse(t.begin(), t.end());
        cout << t << "\n";
    }
}
