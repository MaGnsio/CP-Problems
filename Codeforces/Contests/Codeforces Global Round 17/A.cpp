/**
 *    author:  MaGnsi0
 *    created: 24.11.2021 14:31:16
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
        cout << 2 - (n == 1) - (m == 1) << "\n";
    }
}
