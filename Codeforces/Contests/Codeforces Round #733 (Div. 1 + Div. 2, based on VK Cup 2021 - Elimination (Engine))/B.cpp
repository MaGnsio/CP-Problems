/**
 *    author:  MaGnsi0
 *    created: 20/08/2021 10:09:01
**/
#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> g(h + 2, vector<int>(w + 2, 0));
        int x[2] = {1, h};
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= w; ++j) {
                int sum = 0;
                for (int k = 0; k < 8; ++k) {
                    sum += g[x[i] + dx[k]][j + dy[k]];
                }
                if (!sum) {
                    g[x[i]][j] = 1;
                }
            }
        }
        int y[2] = {1, w};
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= h; ++j) {
                int sum = 0;
                for (int k = 0; k < 8; ++k) {
                    sum += g[j + dx[k]][y[i] + dy[k]];
                }
                if (!sum) {
                    g[j][y[i]] = 1;
                }
            }
        }
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cout << g[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
