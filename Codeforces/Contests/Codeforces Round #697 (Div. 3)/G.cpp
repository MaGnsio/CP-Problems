/**
 *    author:  MaGnsi0
 *    created: 16.09.2024 20:54:09
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ones = 0;
        vector<int> a(N);
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; a[x]++;
        }
        vector<int> dp(N, -1);
        for (int i = N - 1; i; --i) {
            dp[i] = a[i];
            for (int j = 2 * i; j < N; j += i) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        cout << n - dp[1] << "\n";
    }
}
