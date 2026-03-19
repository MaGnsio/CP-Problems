/**
 *    author:  MaGnsi0
 *    created: 12.01.2026 16:37:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n == 2) { cout << 2 << "\n"; }
        else if (n == 3) { cout << 3 << "\n"; }
        else if (n % 2 == 0) { cout << 0 << "\n"; }
        else { cout << 1 << "\n"; }
    }
}
