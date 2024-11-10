/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 17:35:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        int y; cin >> y;
        string s; cin >> s;
        int ok = 0, tx = 0, ty = 0;
        for (int times = 0; times <= 500; ++times) {
            for (int i = 0; i < n; ++i) {
                tx += (s[i] == 'E') - (s[i] == 'W');
                ty += (s[i] == 'N') - (s[i] == 'S');
                ok |= tx == x && ty == y;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
