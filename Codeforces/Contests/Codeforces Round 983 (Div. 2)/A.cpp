/**
 *    author:  MaGnsi0
 *    created: 01.11.2024 16:36:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ones = 0;
        for (int i = 0; i < 2 * n; ++i) {
            int x; cin >> x; ones += x;
        }
        cout << (ones % 2) << " " << (ones <= n ? ones : n - (ones - n)) << "\n";
    }
}
