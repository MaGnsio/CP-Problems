/**
 *    author:  MaGnsi0
 *    created: 12.02.2023 20:03:57
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
        cout << (m * ((n + m - 1) / m)) / n + ((m * ((n + m - 1) / m)) % n != 0) << "\n";
    }
}
