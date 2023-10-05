/**
 *    author:  MaGnsi0
 *    created: 12/08/2021 18:57:35
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, cnt = 0;
        string s, t;
        cin >> n >> s >> t;
        for (int i = 0; i < n; ++i) {
            if (t[i] == '0') {
                continue;
            }
            if (s[i] == '0') {
                cnt++;
            } else if (i && s[i - 1] == '1') {
                s[i - 1] = '2';
                cnt++;
            } else if (i < n - 1 && s[i + 1] == '1') {
                s[i + 1] = '2';
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
