/**
 *    author:  MaGnsi0
 *    created: 03.09.2022 13:58:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> b = a;
    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
    }
    int64_t cur = 0;
    for (int i = 0; i < m; ++i) {
        cur += a[i] * (i + 1);
    }
    int64_t ans = cur;
    for (int i = m; i < n; ++i) {
        cur = cur - (b[i - 1] - (i - m ? b[i - m - 1] : 0)) + m * a[i];
        ans = max(ans, cur);
    }
    cout << ans;
}
