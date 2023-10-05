/**
 *    author:  MaGnsi0
 *    created: 25/07/2021 16:27:09
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, res = 0;
        string s, t;
        cin >> n >> s;
        t = s;
        sort(t.begin(), t.end());
        for (int i = 0; i < n; ++i) {
            res += (s[i] != t[i]);
        }
        cout << res << "\n";
    }
}
