//https://codeforces.com/contest/1525/problem/D
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<int> A, B;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            A.push_back(i);
        } else {
            B.push_back(i);
        }
    }
    int H = A.size(), W = B.size();
    vector<vector<int>> dp(H + 1, vector<int>(W + 1, 100000000));
    for (int i = 0; i <= W; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(A[i - 1] - B[j - 1]));
        }
    }
    cout << dp[H][W];
}
