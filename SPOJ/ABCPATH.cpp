//https://www.spoj.com/problems/ABCPATH/
#include <bits/stdc++.h>
using namespace std;

void dfs(int H, int W, vector<vector<char>>& G, vector<vector<bool>>& V, vector<vector<int>>& D, int i, int j, int dis = 0) {
    D[i][j] = dis + 1;
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            if (!(i + x >= 0 && i + x < H && j + y >= 0 && j + y < W)) {
                continue;
            }
            if (!(V[i + x][j + y] == false && G[i + x][j + y] == G[i][j] + 1 && D[i + x][j + y] < D[i][j] + 1)) {
                continue;
            }
            dfs(H, W, G, V, D, i + x, j + y, D[i][j]);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int H, W, T = 0;
    while ((cin >> H >> W) && H && W) {
        vector<vector<char>> G(H, vector<char>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> G[i][j];
            }
        }
        vector<vector<bool>> V(H, vector<bool>(W, false));
        vector<vector<int>> D(H, vector<int>(W, 0));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (G[i][j] == 'A') {
                    dfs(H, W, G, V, D, i, j);
                }
            }
        }
        int L = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                L = max(L, D[i][j]);
            }
        }
        cout << "Case " << (++T) << ": " << L << "\n";
    }
}
