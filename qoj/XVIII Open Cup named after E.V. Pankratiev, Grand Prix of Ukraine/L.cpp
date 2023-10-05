/**
 *    author:  MaGnsi0
 *    created: 30.09.2023 21:53:03
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> lowX(N, n), lowY(N, m);
    vector<int> highX(N, -1), highY(N, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val; cin >> val;
            lowX[val] = min(lowX[val], i);
            lowY[val] = min(lowY[val], j);
            highX[val] = max(highX[val], i);
            highY[val] = max(highY[val], j);
        }
    }
    int ans = 0;
    vector<pair<int, int>> a[n][m];
    for (int i = 0; i < N; ++i) {
        if (lowX[i] > highX[i]) {
            continue;
        }
        a[lowX[i]][lowY[i]].emplace_back(highX[i], highY[i]);
        ans--;
    }
    for (int i1 = 0; i1 < n; ++i1) {
        for (int j1 = 0; j1 < m; ++j1) {
            for (auto [i2, j2] : a[i1][j1]) {
                for (int i3 = i1; i3 <= i2; ++i3) {
                    for (int j3 = j1; j3 <= j2; ++j3) {
                        for (auto [i4, j4] : a[i3][j3]) {
                            ans += i4 <= i2 && j4 <= j2;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}
