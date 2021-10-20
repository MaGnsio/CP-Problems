/**
 *    author:  MaGnsi0
 *    created: 12/09/2021 16:29:23
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int res = 0;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            int x = (s[i] == '0') + (t[i] == '0');
            int y = (s[i] == '1') + (t[i] == '1');
            v[i] = (x && y ? 2 : (x ? 1 : 0));
        }
        for (int i = 0; i < n; ++i) {
            if (v[i] == 2) {
                res += 2;
                continue;
            }
            if (v[i] == 1) {
                if (i && v[i - 1] == 0) {
                    res += 2;
                    v[i] = 2;
                } else if (i + 1 < n && v[i + 1] == 0) {
                    v[i + 1] = 2;
                } else {
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
}
