/**
 *    author:  MaGnsi0
 *    created: 19.08.2024 19:20:58
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N; cin >> N;
    int64_t K; cin >> K;
    int64_t L; cin >> L;
    int64_t U = N - K;
    int64_t ans = 1;
    for (int64_t i = 1; i <= N; ++i) {
        ans *= max(L - min(i - 1, U), int64_t(0));
        ans %= MOD;
    }
    cout << ans;
}
