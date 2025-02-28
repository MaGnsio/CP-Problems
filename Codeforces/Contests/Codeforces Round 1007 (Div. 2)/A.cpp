/**
 *    author:  MaGnsi0
 *    created: 28.02.2025 16:36:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        cout << (k % 3 == 1 ? "YES" : "NO") << "\n";
    }
}
