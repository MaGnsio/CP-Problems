/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 15:11:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> cnt(20), f(20 * m);
    for (int i = 1; i < 20; ++i) {
        cnt[i] = cnt[i - 1];
        for (int j = 1; j <= m; ++j) {
            cnt[i] += f[i * j] == 0;
            f[i * j]++;
        }
    }
    int64_t ans = 1;
    vector<bool> done(n + 1, false);
    for (int i = 2; i <= n; ++i) {
        if (done[i]) { continue; }
        int64_t k = 1, val = i;
        while (i * val <= n) {
            val *= i;
            done[val] = true;
            k++;
        }
        ans += cnt[k];
    }
    cout << ans;
}
