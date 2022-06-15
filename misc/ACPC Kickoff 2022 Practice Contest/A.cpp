/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 16:02:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("adam.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = (int)s.size();
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'D') {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
}
