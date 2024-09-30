/**
 *    author:  MaGnsi0
 *    created: 30.09.2024 20:16:18
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6, OO = 3e6;

int n, k, a[N], dp[N][1 << 3][3];

int mex(int mask) {
    for (int i = 0; i <= 2; ++i) {
        if (!(mask >> i & 1)) {
            return i;
        }
    }
    return 3;
}

int solve1(int j, int mask, int want) {
    if (j == n) { return 0; }
    int& res = dp[j][mask][want];
    if (res != -1) { return res; }
    res = -OO;
    int nmask = mask | (a[j] <= 2 ? (1 << a[j]) : 0);
    if (mex(nmask) != want) {
        res = max(res, solve1(j + 1, 0, want) + 1);
        res = max(res, solve1(j + 1, nmask, want));
    } else if (j != n - 1) {
        res = max(res, solve1(j + 1, nmask, want));
    }
    return res;
}

int solve2(int j, int mask, int want) {
    if (j == n) { return 0; }
    int& res = dp[j][mask][want];
    if (res != -1) { return res; }
    res = OO;
    int nmask = mask | (a[j] <= 2 ? (1 << a[j]) : 0);
    if (mex(nmask) != want) {
        res = min(res, solve2(j + 1, 0, want) + 1);
        res = min(res, solve2(j + 1, nmask, want));
    } else if (j != n - 1) {
        res = min(res, solve2(j + 1, nmask, want));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> L(3), R(3);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 3; ++i) {
        R[i] = solve1(0, 0, i);
    }
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 3; ++i) {
        L[i] = solve2(0, 0, i);
    }
    for (int i = 0; i < 3; ++i) {
        if (L[i] <= k && k <= R[i]) {
            cout << i << "\n";
            return 0;
        }
    }
    assert(0);
}
