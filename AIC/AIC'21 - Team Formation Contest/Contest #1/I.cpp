/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:46
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            a[i] += x;
            b[j] += x;
        }
    }
    priority_queue<int> qa, qb;
    for (int i = 0; i < n; ++i) {
        qa.push(a[i]);
    }
    for (int i = 0; i < m; ++i) {
        qb.push(b[i]);
    }
    vector<int> dpa(k + 1, 0), dpb(k + 1, 0);
    for (int i = 1; i <= k; ++i) {
        dpa[i] = qa.top(), dpb[i] = qb.top();
        qa.push(dpa[i] - (m * p)), qb.push(dpb[i] - (n * p));
        qa.pop(), qb.pop();
        dpa[i] += dpa[i - 1], dpb[i] += dpb[i - 1];
    }
    int ans = LLONG_MIN;
    for (int i = 0; i <= k; ++i) {
        ans = max(ans, dpa[i] + dpb[k - i] - (i * (k - i) * p));
    }
    cout << ans;
}
