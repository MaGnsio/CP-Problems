/**
 *    author:  MaGnsi0
 *    created: 05/08/2021 05:03:36
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int r1, r2;
        cin >> r1 >> r2;
        int a1 = r1 * r1;
        int a2 = 2 * r2 * r2;
        cout << (a1 > a2 ? 1 : 2) << "\n";
    }
}
