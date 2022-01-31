/**
 *    author:  MaGnsi0
 *    created: 06.01.2022 17:00:09
**/
#include <bits/stdc++.h>

using namespace std;

void compress(vector<int>& L, vector<int>& R, int f = 1) {
    map<int, int> K;
    for (auto& x : L) { K[x]; }
    for (auto& x : R) { K[x]; }
    for (auto& [_, x] : K) { x = f++; }
    for (auto& x : L) { x = K[x]; }
    for (auto& x : R) { x = K[x]; }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> L(n), R(n), C(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i] >> C[i];
    }
    compress(L, R);
    int m = 2 * n + 2;
    vector<vector<pair<int, int>>> end_at(m);
    for (int i = 0; i < n; ++i) {
        end_at[R[i]].emplace_back(L[i] - 1, C[i]);
    }
    vector<long long> dp(m, 0);
    for (int i = 1; i < m; ++i) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < (int)end_at[i].size(); ++j) {
            dp[i] = max(dp[i], dp[end_at[i][j].first] + end_at[i][j].second);
        }
    }
    cout << dp[m - 1];
}
