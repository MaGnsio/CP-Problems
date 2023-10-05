/**
 *    author:  MaGnsi0
 *    created: 19.04.2022 16:28:56
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
        if (n > m) {
            swap(n, m);
        }
        if (n == 1 && m > 2) {
            cout << -1 << "\n";
            continue;
        }
        cout << 2 * (n - 1) + (m != n ? 2 * (m - n) - (m - n) % 2 : 0) << "\n";
    }
}
