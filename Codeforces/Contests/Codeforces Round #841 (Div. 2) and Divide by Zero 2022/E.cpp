/**
 *    author:  MaGnsi0
 *    created: 27.12.2022 20:25:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        vector<int64_t> cnt(n + 1, 0);
        for (int i = n; i > 0; --i) {
            int64_t x = n / i;
            cnt[i] = x * (x - 1) / 2;
            for (int j = 2 * i; j < n; j += i) {
                cnt[i] -= cnt[j];
            }
        }
        int64_t ans = 0;
        for (int i = n; i > 1; --i) {
            int64_t t = min(m, cnt[i]) / (i - 1);
            ans += t * i;
            m -= t * (i - 1);
        }
        cout << (m ? -1 : ans) << "\n";
    }
}
