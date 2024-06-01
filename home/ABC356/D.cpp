/**
 *    author:  MaGnsi0
 *    created: 01.06.2024 15:11:07
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t B = 61, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N; cin >> N; N++;
    int64_t M; cin >> M;
    int64_t ans = 0;
    for (int b = 0; b <= B; ++b) {
        if (!(M >> b & 1)) { continue; }
        int64_t count = (N >> (b + 1)) << b;
        if ((N >> b) & 1) {
            count += N & ((1LL << b) - 1);
        }
        ans = (ans + count) % MOD;
    }
    cout << ans;
}
