/**
 *    author:  MaGnsi0
 *    created: 07.08.2023 23:11:21
**/
#include <bits/stdc++.h>

using namespace std;

const int Nax = 31;


int64_t L, R, dp[Nax][2][2][2][2];

int64_t solve(int b, int tieL1, int tieL2, int tieR1, int tieR2) {
    if (b < 0) { return 1; }
    int64_t& ans = dp[b][tieL1][tieL2][tieR1][tieR2];
    if (ans != -1) { return ans; }
    ans = 0;
    for (int b1 = 0; b1 < 2; ++b1) {
        for (int b2 = 0; b2 < 2; ++b2) {
            if (b1 & b2) { continue; }
            if (tieL1 == 0 && (L >> b & 1) && b1 == 0) { continue; }
            if (tieL2 == 0 && (L >> b & 1) && b2 == 0) { continue; }
            if (tieR1 == 0 && ((R >> b & 1) == 0) && b1 == 1) { continue; }
            if (tieR2 == 0 && ((R >> b & 1) == 0) && b2 == 1) { continue; }
            int new_tieL1 = tieL1 || (((L >> b) & 1) == 0 && b1 == 1);
            int new_tieL2 = tieL2 || (((L >> b) & 1) == 0 && b2 == 1);
            int new_tieR1 = tieR1 || (((R >> b) & 1) == 1 && b1 == 0);
            int new_tieR2 = tieR2 || (((R >> b) & 1) == 1 && b2 == 0);
            ans += solve(b - 1, new_tieL1, new_tieL2, new_tieR1, new_tieR2);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> L >> R;
        memset(dp, -1, sizeof dp);
        cout << solve(Nax - 1, 0, 0, 0, 0) << "\n";
    }
}
