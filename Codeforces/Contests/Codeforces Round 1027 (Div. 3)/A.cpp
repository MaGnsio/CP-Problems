/**
 *    author:  MaGnsi0
 *    created: 26.05.2025 17:59:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = stoi(s);
        int x = -1, y = -1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; (i + j) * (i + j) <= n; ++j) {
                if ((i + j) * (i + j) == n) {
                    x = i, y = j;
                }
            }

        }
        if (x == -1) {
            cout << "-1\n";
        } else {
            cout << x << " " << y << "\n";
        }
    }
}
