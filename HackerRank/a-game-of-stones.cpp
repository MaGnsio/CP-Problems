/**
 *    author:  MaGnsi0
 *    created: 21.09.2022 22:45:50
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> dp(N, 0);
    for (int i = 0; i < N; ++i) {
        if (i >= 2) {
            dp[i] |= !dp[i - 2];
        }
        if (i >= 3) {
            dp[i] |= !dp[i - 3];
        }
        if (i >= 5) {
            dp[i] |= !dp[i - 5];
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << (dp[n] ? "First" : "Second") << "\n";
    }
}
