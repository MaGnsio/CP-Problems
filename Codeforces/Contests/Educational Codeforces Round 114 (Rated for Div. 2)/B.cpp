/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 16:32:53
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int a[3], m;
        cin >> a[0] >> a[1] >> a[2] >> m;
        sort(a, a + 3);
        int maxm = a[0] + a[1] + a[2] - 3;
        int minm = (a[2] - a[1] - a[0] <= 0 ? 0 : a[2] - a[1] - a[0] - 1); 
        cout << (maxm >= m && m >= minm ? "YES\n" : "NO\n");
    }
}
