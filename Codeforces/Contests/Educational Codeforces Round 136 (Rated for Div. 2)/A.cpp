/**
 *    author:  MaGnsi0
 *    created: 29.09.2022 16:36:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n >= 3 && m >= 3) {
            cout << 2 << " " << 2 << "\n";
        } else if (n < 3 && m < 3) {
            cout << 1 << " " << 1 << "\n";
        } else if (n < 3) {
            cout << 1 << " " << 2 << "\n";
        } else {
            cout << 2 << " " << 1 << "\n";
        }
    }
}
