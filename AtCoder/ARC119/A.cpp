/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 20:58:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N;
    cin >> N;
    int64_t ans = N;
    for (int i = 0; i <= 60; ++i) {
        if ((1LL << i) > N) {
            break;
        }
        int L = 1, R = N / (1LL << i), A = L;
        while (L <= R) {
            int64_t M = L + (R - L) / 2;
            if (M * (1LL << i) <= N) {
                A = M;
                L = M + 1;
            } else {
                R = M - 1;
            }
        }
        ans = min(ans, int64_t(i + A + N - A * (1LL << i)));
    }
    cout << ans;
}
