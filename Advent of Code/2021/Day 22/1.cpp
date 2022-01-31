/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 15:10:41
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 50;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input1.txt", "r", stdin);
    int type;
    bool a[2 * N + 2][2 * N + 2][2 * N + 2];
    memset(a, 0, sizeof a);
    while (cin >> type) {
        int x0, x1, y0, y1, z0, z1;
        cin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
        x0 = max(x0, -N);
        y0 = max(y0, -N);
        z0 = max(z0, -N);
        x1 = min(x1, N);
        y1 = min(y1, N);
        z1 = min(z1, N);
        x0 += N, y0 += N, z0 += N;
        x1 += N, y1 += N, z1 += N;
        for (int i = x0; i <= x1; ++i) {
            for (int j = y0; j <= y1; ++j) {
                for (int k = z0; k <= z1; ++k) {
                    a[i][j][k] = type;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 2 * N + 2; ++i) {
        for (int j = 0; j < 2 * N + 2; ++j) {
            for (int k = 0; k < 2 * N + 2; ++k) {
                res += a[i][j][k];
            }
        }
    }
    cout << res;
}
