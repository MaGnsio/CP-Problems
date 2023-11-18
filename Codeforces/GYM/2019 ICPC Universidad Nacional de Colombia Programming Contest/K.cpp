/**
 *    author:  MaGnsi0
 *    created: 02.11.2023 11:23:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << (n - 1) - ((n + 1) / 3) + (n > 2) << "\n";
    }
}
