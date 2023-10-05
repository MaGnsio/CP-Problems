/**
 *    author:  MaGnsi0
 *    created: 10/07/2021 16:45:41
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s, t, p = "";
        cin >> s;
        t = s;
        for (char i = 'a'; i <= 'z'; ++i) {
            p += i;
        }
        sort(t.begin(), t.end());
        if (t != p.substr(0, s.size())) {
            cout << "NO\n";
            continue;
        }
        int idx;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') {
                idx = i;
                break;
            }
        }
        bool ok = true;
        for (int i = idx + 2; i < s.size(); ++i) {
            if (s[i] < s[i - 1]) {
                ok = false;
            }
        }
        for (int i = idx - 2; i >= 0; --i) {
            if (s[i] < s[i + 1]) {
                ok = false;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
