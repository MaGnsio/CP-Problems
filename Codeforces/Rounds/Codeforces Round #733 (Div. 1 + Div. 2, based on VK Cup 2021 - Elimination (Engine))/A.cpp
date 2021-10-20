/**
 *    author:  MaGnsi0
 *    created: 20/08/2021 10:01:31
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, res = 0;
        cin >> n;
        while (n) {
            res = max(res, n % 10);
            n /= 10;
        }
        cout << res << "\n";
    }
}
