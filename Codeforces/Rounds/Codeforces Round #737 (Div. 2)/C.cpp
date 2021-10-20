/**
 *    author:  MaGnsi0
 *    created: 13/08/2021 20:18:54
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e9 + 7, N = 2e5 + 5;
int n, k, t, e;
int dp[N][2];

int biExp(int b, int p, int m) {
    int res = 1;
    while (p) {
        if (p & 1) {
            res = ((res % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p >>= 1LL;
    }
    return res;
}

int solve(int i, int tight) {
    int ret = 0;
    if (i == k) {
        //all bits completed
        return 1;
    }
    if (dp[i][tight] != -1) {
        //the state is already computed
        return dp[i][tight];
    }
    if (tight) {
        //and -> 1, xor -> 0 (only if n is even)
        //and -> 1, xor -> 1 (only if n is odd)
        ret += solve(i + 1, (n & 1 ? tight : !tight)) % M;
        //and -> 0, xor -> 0 (even number of 1's and there is one 0)
        //nc0 + nc1 + nc2 + nc3 + ... ncn = 2^n -> nc0 + nc2 + nc4 + ... = (2^n)/2 = 2^(n - 1)
        ret += ((e - (n % 2 == 0)) * solve(i + 1, tight)) % M;
    } else {
        ret += (t * solve(i + 1, tight)) % M;
    }
    return dp[i][tight] = ret % M;
}

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        memset(dp, -1, sizeof dp);
        t = biExp(2, n, M);
        e = biExp(2, n - 1, M);
        cout << solve(0, 1) << "\n";
    }
}
