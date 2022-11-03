/**
 *    author:  MaGnsi0
 *    created: 01.08.2022 21:44:26
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, M = 60;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> ugliness(N, 0);
    for (int i = 2; i < N; ++i) {
        if (!ugliness[i]) {
            for (int j = i; j < N; j += i) {
                ugliness[j]++;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int sum = accumulate(a.begin(), a.end(), 0);
        vector<bitset<N>> dp(M, 0);
        dp[0][0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = M - 1; j >= 0; --j) {
                if (j + ugliness[a[i]] >= M) {
                    continue;
                }
                dp[j + ugliness[a[i]]] |= (dp[j] << a[i]);
            }
        }
        int ans = INT_MAX;
        for (int i = l; i <= r; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dp[i][j]) {
                    ans = min(ans, abs(sum - 2 * j));
                }
            }
        }
        cout << (ans == INT_MAX ? -1 : ans) << "\n";
    }
}
