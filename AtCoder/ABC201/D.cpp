//https://atcoder.jp/contests/abc201/tasks/abc201_d
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> V(H, vector<int>(W)), dp(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char x;
            cin >> x;
            V[i][j] = (x == '+' ? 1 : -1);
        }
    }
    for (int i = H - 1; i >= 0; --i) {
        for (int j = W - 1; j >= 0; --j) {
            if ((i + j) & 1) {
                if (i + 1 < H && j + 1 < W) {
                    dp[i][j] = min(dp[i + 1][j] - V[i + 1][j], dp[i][j + 1] - V[i][j + 1]);
                } else if (i + 1 < H) {
                    dp[i][j] = dp[i + 1][j] - V[i + 1][j];
                } else if (j + 1 < W) {
                    dp[i][j] = dp[i][j + 1] - V[i][j + 1];
                }
            } else {
                if (i + 1 < H && j + 1 < W) {
                    dp[i][j] = max(dp[i + 1][j] + V[i + 1][j], dp[i][j + 1] + V[i][j + 1]);
                } else if (i + 1 < H) {
                    dp[i][j] = dp[i + 1][j] + V[i + 1][j];
                } else if (j + 1 < W) {
                    dp[i][j] = dp[i][j + 1] + V[i][j + 1];
                }
            }
        }
    }
    if (dp[0][0] == 0) {
        cout << "Draw";
    } else {
        cout << (dp[0][0] > 0 ? "Takahashi" : "Aoki");
    }
}
