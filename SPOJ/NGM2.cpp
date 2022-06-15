/**
 *    author:  MaGnsi0
 *    created: 28.05.2022 14:45:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int64_t> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    int64_t ans = n;
    for (int i = 1; i < (1 << k); ++i) {
        int64_t lcm = 1;
        for (int j = 0; j < k; ++j) {
            if ((i >> j) & 1) {
                lcm = (lcm * a[j]) / __gcd(lcm, a[j]);
            }
        }
        ans += (__builtin_popcount(i) & 1 ? -1 : 1) * (n / lcm);
    }
    cout << ans;
}
