/**
 *    author:  MaGnsi0
 *    created: 22.07.2023 11:18:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("green.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int N, M, R;
        cin >> N >> M >> R;
        int64_t ans = 0;
        for (int K = 1; K < min({N, M, R}); ++K) {
            vector<vector<int>> C(3);
            C[0].push_back(1), C[0].push_back(1), C[0].push_back(N - K - 1);
            C[1].push_back(1), C[1].push_back(1), C[1].push_back(M - K - 1);
            C[2].push_back(1), C[2].push_back(1), C[2].push_back(R - K - 1);
            int64_t val = 0;
            for (int x1 = 0; x1 < 3; ++x1) {
                for (int x2 = 0; x2 < 3; ++x2) {
                    for (int x3 = 0; x3 < 3; ++x3) {
                        bool ok0 = (x1 == 0) || (x2 == 0) || (x3 == 0);
                        bool ok1 = (x1 == 1) || (x2 == 1) || (x3 == 1);
                        if (!ok0 || !ok1) { continue; }
                        val += C[0][x1] * C[1][x2] * C[2][x3];
                    }
                }
            }
            ans ^= val;
        }
        int64_t maxK = 1, K = min({N, M, R});
        if (N > K) {
            maxK *= N - K + 1;
        }
        if (M > K) {
            maxK *= M - K + 1;
        }
        if (R > K) {
            maxK *= R - K + 1;
        }
        ans ^= maxK;
        cout << ans << "\n";
    }
}
