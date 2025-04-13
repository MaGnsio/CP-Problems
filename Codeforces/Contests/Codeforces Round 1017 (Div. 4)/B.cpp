/**
 *    author:  MaGnsi0
 *    created: 13.04.2025 20:15:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int l; cin >> l;
        int r; cin >> r;
        for (int x = l; x <= r; ++x) {
            if (x + m >= 0) {
                cout << x << " " << x + m << "\n";
                break;
            }
        }
    }
}
