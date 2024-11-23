/**
 *    author:  MaGnsi0
 *    created: 23.11.2024 16:35:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            cout << 2 * i - 1 << " ";
        }
        cout << "\n";
    }
}
