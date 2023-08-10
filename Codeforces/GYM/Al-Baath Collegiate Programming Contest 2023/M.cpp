/**
 *    author:  MaGnsi0
 *    created: 07.07.2023 01:40:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            cout << 0 << "\n";
        } else if (n == m) {
            cout << 1 << " " << n << "\n";
        } else if (abs(n) % 2 != abs(m) % 2) {
            cout << -1 << "\n";
        } else {
            cout << 2 << " " << (n + m) / 2 << " " << (n - m) / 2 << "\n";
        }
    }
}
