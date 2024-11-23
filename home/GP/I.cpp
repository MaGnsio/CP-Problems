/**
 *    author:  MaGnsi0
 *    created: 23.11.2024 13:43:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    for (int i = 0; i < n - 1; ++i) {
        cout << 1 << " " << 1 << " " << 3 << " " << 4 << "\n";
    }
    cout << 2 * n - 2 << " " << m - n + 1 << " " << 1 << " " << m - 4 * n + 4 << "\n";
}
