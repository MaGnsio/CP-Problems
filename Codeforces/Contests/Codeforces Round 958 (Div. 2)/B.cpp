/**
 *    author:  MaGnsi0
 *    created: 15.07.2024 21:59:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                cnt++;
            } else if (i == 0 || s[i - 1] != '0') {
                cnt--;
            }
        }
        cout << (cnt > 0 ? "YES" : "NO") << "\n";
    }
}
