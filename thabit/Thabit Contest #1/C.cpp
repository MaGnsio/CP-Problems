/**
 *    author:  MaGnsi0
 *    created: 19/06/2021 16:37:58
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k, m, sum = 0;
    cin >> n >> k >> m;
    vector<int> a(n), b(n);
    bool s = false, c = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] % 2 == b[i] % 2) {
            c = true;
        } else {
            s = true;
        }
        sum += a[i];
    }
    if (c && s) {
        cout << (k & 1 ? 1 : 2);
    } else if (s == 0) {
        cout << (sum % 2 == m ? 1 : 2);
    } else {
        int p = (k & 1 ? ((sum % 2 == 0) ? 1 : 0) : (sum % 2));
        cout << (p == m ? 1 : 2);
    }
}
