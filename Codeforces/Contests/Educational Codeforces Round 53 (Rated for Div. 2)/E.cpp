/**
 *    author:  MaGnsi0
 *    created: 16.10.2023 23:12:00
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int K;
string N, L, R;
bool done[20][1 << 10][2][2];
pair<int64_t, int64_t> dp[20][1 << 10][2][2];

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

pair<int64_t, int64_t> solve(int j, int mask, int tie, int started) {
    if (j == 20) { return {0, 1}; }
    pair<int64_t, int64_t>& ans = dp[j][mask][tie][started];
    if (done[j][mask][tie][started]) { return ans; }
    done[j][mask][tie][started] = true;
    ans = {0, 0};
    for (int x = 0; x < 10; ++x) {
        if (!tie && N[j] - '0' < x) {
            continue;
        }
        int new_mask = mask;
        if (started || x) {
            new_mask |= 1 << x;
        }
        if (__builtin_popcount(new_mask) > K) { continue; }
        pair<int64_t, int64_t> add = solve(j + 1, new_mask, tie || (N[j] - '0' > x), started || x);
        ans.first = (ans.first + add.first + add.second * x * power(10, 20 - j - 1) % MOD) % MOD;
        ans.second = (ans.second + add.second) % MOD;
    }
    return ans;
}

int64_t F(string x) {
    N = x;
    memset(done, 0, sizeof done);
    reverse(N.begin(), N.end());
    while ((int)N.size() < 20) { N += "0"; }
    reverse(N.begin(), N.end());
    return solve(0, 0, 0, 0).first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> L >> R >> K;
    cout << (F(R) - F(to_string(stoll(L) - 1)) + MOD) % MOD;
}
