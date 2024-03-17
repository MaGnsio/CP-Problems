/**
 *    author:  MaGnsi0
 *    created: 20.11.2023 15:55:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        string s; cin >> s;
        int B = 0;
        for (int i = 0; i < n; ++i) {
            B += s[i] == 'B';
        }
        if (B == k) {
            cout << 0 << "\n";
        } else {
            int ans = 2;
            for (int i = 0; i < n; ++i) {
                B -= s[i] == 'B';
                if (B == k) {
                    ans = 1;
                    cout << ans << "\n";
                    cout << i + 1 << " A\n";
                    break;
                }
                if (B + i + 1 == k) {
                    ans = 1;
                    cout << ans << "\n";
                    cout << i + 1 << " B\n";
                    break;
                }
            }
            if (ans == 2) {
                cout << ans << "\n";
                cout << n << " A\n";
                cout << k << " B\n";
            }
        }
    }
}
