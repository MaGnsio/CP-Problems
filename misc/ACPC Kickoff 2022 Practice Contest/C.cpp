/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 16:14:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("self.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        string n;
        cin >> n;
        bool ok = true;
        for (int i = 0; i < (int)n.size(); ++i) {
            ok &= bool(count(n.begin(), n.end(), char('0' + i)) == n[i] - '0');
        }
        cout << (ok ? "self-describing" : "not self-describing") << "\n";
    }
}
