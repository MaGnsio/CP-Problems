/**
 *    author:  MaGnsi0
 *    created: 14.11.2021 14:18:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long u,  v;
        cin >> u >> v;
        cout << u * u << " " << -1 * v * v << "\n";
    }
}
