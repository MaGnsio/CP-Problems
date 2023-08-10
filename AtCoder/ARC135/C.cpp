/**
 *    author:  MaGnsi0
 *    created: 22.06.2023 11:10:07
**/
#include <bits/stdc++.h>

using namespace std;

int m = 31;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            b[j] += (a[i] >> j) & 1;
        }
    }
    int64_t ans = accumulate(a.begin(), a.end(), int64_t(0));
    for (int i = 0; i < n; ++i) {
        int64_t val = 0;
        for (int j = 0; j < m; ++j) {
            if ((a[i] >> j) & 1) {
                val += (n - b[j]) * (1LL << j);
            } else {
                val += b[j] * (1LL << j);
            }
        }
        ans = max(ans, val);
    }
    cout << ans;
}
