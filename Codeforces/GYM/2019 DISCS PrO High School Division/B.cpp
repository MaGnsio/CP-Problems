/**
 *    author:  MaGnsi0
 *    created: 31/07/2021 09:43:18
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, x, cnt = 0;
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            cnt += (gcd(a, x) > 1);
        }
    }
    cout << cnt;
}
