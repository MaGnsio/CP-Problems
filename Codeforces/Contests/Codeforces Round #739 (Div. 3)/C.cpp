/**
 *    author:  MaGnsi0
 *    created: 18/08/2021 16:27:51
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int k = ceil(sqrt(n));
        int st = (k - 1) * (k - 1) + 1;
        int l = k * k - (k - 1) * (k - 1);
        int r, c;
        if (n < st + (l / 2)) {
            r = n - st + 1;
        } else {
            r = (l / 2) + 1;
        }
        if (n <= st + (l / 2)) {
            c = k;
        } else {
            c = (st + l - 1) - n + 1;
        }
        cout << r << " " << c << "\n";
    }
}
