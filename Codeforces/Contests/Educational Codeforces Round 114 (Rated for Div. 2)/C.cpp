/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 16:32:54
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> p(n);
    p[0] = v[0];
    for (int i = 1; i < n; ++i) {
        p[i] = v[i] + p[i - 1];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it == v.end()) {
            cout << max(0LL, x - v[n - 1]) + max(0LL, y - p[n - 2]) << "\n";
        } else {
            int idx = it - v.begin();
            int sum1 = max(0LL, y - ((idx ? p[idx - 1] : 0LL) + (p[n - 1] - p[idx])));
            idx--;
            int sum2 = (idx == -1 ? LLONG_MAX : max(0LL, x - v[idx]) + max(0LL, y - ((idx ? p[idx - 1] : 0LL) + (p[n - 1] - p[idx]))));
            cout << min(sum1, sum2) << "\n";
        }
    }
}
