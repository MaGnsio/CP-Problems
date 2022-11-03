/**
 *    author:  MaGnsi0
 *    created: 21.09.2022 22:55:09
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
        cout << ((m != 1) && (n & 1) ? 1 : 2) << "\n";
    }
}
