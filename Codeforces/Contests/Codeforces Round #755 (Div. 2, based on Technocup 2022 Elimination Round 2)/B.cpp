/**
 *    author:  MaGnsi0
 *    created: 14.11.2021 14:22:27
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
        cout << ((n * m) / 3 + ((n * m) % 3 != 0)) << "\n";
    }
}
