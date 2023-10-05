/**
 *    author:  MaGnsi0
 *    created: 08.10.2021 17:16:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        if (count(s.begin(), s.end(), c) == n) {
            cout << "0\n";
            continue;
        }
        if (s[n - 1] == c) {
            cout << "1\n" << n << "\n";
            continue;
        }
        int ans = -1;
        for (int i = 2; i <= n; ++i) {
            bool ok = true;
            for (int j = i; j <= n; j += i) {
                if (s[j - 1] != c) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = i;
                break;
            }
        }
        if (ans != -1) {
            cout << "1\n" << ans << "\n";
            continue;
        }
        cout << "2\n";
        for (int i = 2; i < n; ++i) {
            if (n % i != 0) {
                cout << i << " ";
                break;
            }
        }
        cout << n << "\n";
    }
}
