/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 18:11:15
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](int64_t x, int64_t y) { return abs(x) > abs(y); });
    int64_t ans = 1;
    for (int i = 0; i < m; ++i) {
        ans *= abs(a[i]);
        ans %= MOD;
    }
    cout << ans;
}
