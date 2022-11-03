/**
 *    author:  MaGnsi0
 *    created: 31.07.2022 16:01:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        string a, b;
        cin >> n >> m >> a >> b;
        if (n == m) {
            cout << (a == b ? "YES" : "NO") << "\n";
            continue;
        }
        string s = "";
        for (int i = 0; i < n - m + 1; ++i) {
            if (a[i] == b[0]) {
                s += a[i];
                break;
            }
        }
        s += a.substr(n - m + 1);
        cout << (s == b ? "YES" : "NO") << "\n";
    }
}
