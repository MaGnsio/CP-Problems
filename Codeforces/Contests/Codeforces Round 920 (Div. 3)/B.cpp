/**
 *    author:  MaGnsi0
 *    created: 16.01.2024 16:35:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string a; cin >> a;
        string b; cin >> b;
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) { continue; }
            x += a[i] == '1';
            y += a[i] == '0';
        }
        cout << max(x, y) << "\n";
    }
}
