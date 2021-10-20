/**
 *    author:  MaGnsi0
 *    created: 30/07/2021 01:06:01
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, sum = 0;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }
        for (int i = 0; i < n; ++i) {
            v[i] = (n - k) * sum - v[i];
        }
        sort(v.begin(), v.end());
        cout << v[n - 1] - v[0] << "\n";
    }
}
