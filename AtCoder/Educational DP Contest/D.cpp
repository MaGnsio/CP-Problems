/**
 *    author:  MaGnsi0
 *    created: 02/09/2021 15:41:44
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, W;
    cin >> N >> W;
    vector<long long> w(N), v(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }
    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = W; j; --j) {
            if (w[i] <= j) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[W];
}
