/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 14:03:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N; cin >> N;
    int64_t S; cin >> S;
    int64_t M; cin >> M;
    int64_t L; cin >> L;
    int64_t ans = INT64_MAX;
    for (int64_t s = 0; s <= 100; ++s) {
        for (int64_t m = 0; m <= 100; ++m) {
            for (int64_t l = 0; l <= 100; ++l) {
                int64_t have = 6 * s + 8 * m + 12 * l;
                if (have >= N) {
                    ans = min(ans, S * s + M * m + L * l);
                }
            }
        }
    }
    cout << ans;
}
