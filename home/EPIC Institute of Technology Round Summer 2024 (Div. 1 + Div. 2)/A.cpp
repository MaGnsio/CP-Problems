/**
 *    author:  MaGnsi0
 *    created: 30.06.2024 17:36:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        cout << (n - 1) * (k - 1) + n << "\n";
    }
}
