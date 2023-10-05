/**
 *    author:  MaGnsi0
 *    created: 24.08.2023 18:29:39
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int w, f, n;
        cin >> w >> f >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bitset<N> dp(0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            dp |= (dp << a[i]);
        }
        int ans = INT_MAX, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        for (int i = 0; i < N; ++i) {
            if (!dp[i]) { continue; }
            int x = i, y = sum - i;
            ans = min(ans, max((x + w - 1) / w, (y + f - 1) / f));
        }
        cout << ans << "\n";
    }
}
