/**
 *    author:  MaGnsi0
 *    created: 21.02.2023 19:29:13
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
        if (n & 1) {
            cout << -1 << "\n";
        } else {
            cout << 1 << " " << n / 2 << "\n";
        }
    }
}
