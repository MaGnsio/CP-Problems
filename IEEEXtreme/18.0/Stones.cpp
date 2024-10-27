/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 23:52:42
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 45;

bool done[2][N][N][N][N];
double dp[2][N][N][N][N];

double solve(int t, int b1, int r1, int b2, int r2) {
    if (!b1 || !r1) { return 0.0; }
    if (!b2 || !r2) { return 1.0; }
    double& res = dp[t][b1][r1][b2][r2];
    if (done[t][b1][r1][b2][r2]) { return res; }
    done[t][b1][r1][b2][r2] = true;
    res = 0.0;
    double val1 = 0.5 * solve(t^1, b1, r1 - 1, b2, r2) + 0.5 * solve(t^1, b1, r1, b2 - 1, r2);
    double val2 = 0.5 * solve(t^1, b1 - 1, r1, b2, r2) + 0.5 * solve(t^1, b1, r1, b2, r2 - 1);
    double val3 = 0.5 * solve(t^1, b1 - 1, r1, b2, r2) + 0.5 * solve(t^1, b1, r1, b2 - 1, r2);
    double val4 = 0.5 * solve(t^1, b1, r1 - 1, b2, r2) + 0.5 * solve(t^1, b1, r1, b2, r2 - 1);
    if (t & 1) {
        res = 0.5 * (isgreater(val1, val2) ? (isgreater(val3, val4) ? solve(t^1, b1 - 1, r1, b2, r2) : solve(t^1, b1, r1, b2, r2 - 1)) : (isgreater(val3, val4) ? solve(t^1, b1, r1, b2 - 1, r2) : solve(t^1, b1, r1 - 1, b2, r2)));
    } else {
        res = 0.5 * (isgreater(val1, val2) ? (isgreater(val3, val4) ? solve(t^1, b1, r1 - 1, b2, r2) : solve(t^1, b1, r1, b2 - 1, r2)) : (isgreater(val3, val4) ? solve(t^1, b1, r1, b2, r2 - 1) : solve(t^1, b1 - 1, r1, b2, r2)));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(done, 0, sizeof done);
    int b1, r1, b2, r2;
    cin >> b1 >> r1 >> b2 >> r2;
    cout << fixed << setprecision(10) << solve(0, b1, r1, b2, r2);
}
