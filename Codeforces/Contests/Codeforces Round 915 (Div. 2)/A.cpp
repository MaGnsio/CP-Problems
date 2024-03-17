/**
 *    author:  MaGnsi0
 *    created: 18.12.2023 14:06:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        cout << max(n, m) << "\n";
    }
}
