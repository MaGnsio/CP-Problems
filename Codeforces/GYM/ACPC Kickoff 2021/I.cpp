/**
 *    author:  MaGnsi0
 *    created: 21.03.2022 15:56:42
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 3;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("binary.in", "r", stdin);
    int n, x;
    string s;
    cin >> n >> x >> s;
    for (int k = 1; k <= n; ++k) {
        vector<vector<int>> cnt(2, vector<int>(k, 0));
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - '0'][i % k]++;
        }
        bitset<N> dp(1);
        for (int i = 0; i < k; ++i) {
            dp = (dp << cnt[0][i]) | (dp << cnt[1][i]);
        }
        if (dp[x]) {
            cout << k;
            return 0;
        }
    }
    cout << n;
}
