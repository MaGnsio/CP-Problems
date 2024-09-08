/**
 *    author:  MaGnsi0
 *    created: 08.09.2024 19:33:54
**/
#include <bits/stdc++.h>

using namespace std;

struct weapon {
    int64_t A, B, C;
    weapon() {};
    weapon(int64_t a, int64_t b, int64_t c) : A(a), B(b), C(c) {};
};

const int64_t N = 205, M = 1e5 + 10, OO = 1e15;
int64_t n, p, dp[N][M];
weapon weapons[N];

int64_t solve(int j, int power) {
    if (j == n) { return 0; }
    if (dp[j][power] != -1) { return dp[j][power]; }
    dp[j][power] = solve(j + 1, power);
    if (power >= weapons[j].B) {
        dp[j][power] = max(dp[j][power], solve(j + 1, (power - weapons[j].B) / weapons[j].A) + weapons[j].C);
    }
    return dp[j][power];
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        int64_t A; cin >> A;
        int64_t B; cin >> B;
        int64_t C; cin >> C;
        weapons[i] = weapon(A, B, C);
    }
    sort(weapons, weapons + n, [](weapon x, weapon y) {
            int64_t L1 = x.B + x.A * y.B;
            int64_t L2 = y.B + y.A * x.B;
            return L1 < L2;
        });
    memset(dp, -1, sizeof dp);
    int64_t ans = solve(0, p);
    cout << ans;
}
