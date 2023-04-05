/**
 *    author:  MaGnsi0
 *    created: 04.11.2022 16:40:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << (n + 1) / 2 << "\n";
        for (int i = 0, j = 1, k = n; i < (n + 1) / 2; ++i, ++j, --k) {
            cout << 3 * (j - 1) + 1 << " " << 3 * (k - 1) + 3 << "\n";
        }
    }
}
