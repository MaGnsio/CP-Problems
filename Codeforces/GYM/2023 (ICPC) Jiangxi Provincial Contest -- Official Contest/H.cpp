/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 19:02:44
**/
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int N = 250000 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    bitset<N> dp(0);
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        dp = 0;
        vector<int> b(n);
        vector<bool> done(n, false);
        for (int i = 0; i < n; ++i) {
            b[a[i]] = i;
        }
        dp[0] = 1;
        for (int i = n - 1; i >= 0; --i) {
            int x = 0;
            for (int j = b[i]; j < n; ++j) {
                if (done[j]) { break; }
                done[j] = true;
                x++;
            }
            if (x) {
                dp = dp | (dp << x);
            }
            if (dp[n / 2]) { break; }
        }
        cout << (dp[n / 2] ? "Yes" : "No") << "\n";
    }
}
