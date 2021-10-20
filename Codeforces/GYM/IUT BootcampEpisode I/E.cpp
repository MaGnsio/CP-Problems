/**
 *    author:  MaGnsi0
 *    created: 11/07/2021 22:04:35
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, cnt = 0;
        cin >> n;
        vector<int> t(n), x(n), p(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> t[i] >> x[i];
        }
        int l = -1, d = 1;
        for (int i = 0; i < n; ++i) {
            if (l != -1 && t[l] + abs(x[l] - p[l]) > t[i]) {
                p[i] = d * abs(t[l] - t[i]) + p[l];
            } else {
                d = ((l != -1 ? x[l] : 0) > x[i] ? -1 : 1);
                p[i] = (l == -1 ? 0 : x[l]);
                l = i;
            }
        }
        p[n] = x[l];
        for (int i = 0; i < n; ++i) {
            int a = min(p[i], p[i + 1]), b = max(p[i], p[i + 1]);
            if (x[i] >= a && x[i] <= b) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
