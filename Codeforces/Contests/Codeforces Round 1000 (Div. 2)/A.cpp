/**
 *    author:  MaGnsi0
 *    created: 22.01.2025 17:25:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int l; cin >> l;
        int r; cin >> r;
        if (l == r) {
            cout << (l == 1 ? 1 : 0) << "\n";
        } else {
            cout << r - l << "\n";
        }
    }
}
