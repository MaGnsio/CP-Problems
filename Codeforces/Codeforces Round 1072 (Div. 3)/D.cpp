/**
 *    created: 12.01.2026 17:42:49
**/
#include <bits/stdc++.h>

using namespace std;

int C(int n, int k) {
    int ans = 1;
    map<int, int> f;
    for (int i = n - k + 1; i <= n; ++i) {
        int x = i;
        for (int j = 2; j * j <= x; ++j) {
            while (x % j == 0) {
                f[j]++;
                x /= j;
            }
        }
        if (x > 1) { f[x]++; }
    }
    for (int i = 1; i <= k; ++i) {
        int x = i;
        for (int j = 2; j * j <= x; ++j) {
            while (x % j == 0) {
                f[j]--;
                x /= j;
            }
        }
        if (x > 1) { f[x]--; }
    }
    for (auto [p, c] : f) {
        for (int i = 0; i < c; ++i) {
            ans *= p;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int m = log2(n);
        int ans = m + 1 > k;
        for (int s = 0; s < m; ++s) {
            ans += s + 1 > k;
            for (int b = 1; b <= s; ++b) {
                if (s + b + 1 <= k) { continue; }
                ans += C(s, b);
            }
        }
        cout << ans << "\n";
    }
}
