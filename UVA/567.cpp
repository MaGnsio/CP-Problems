/**
 *    author:  MaGnsi0
 *    created: 22/06/2021 05:30:04
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int T = 1; ; ++T) {
        vector<vector<int>> g(20, vector<int>(20, 10000));
        for (int i = 0; i < 20; ++i) {
            g[i][i] = 0;
        }
        for (int i = 0; i < 19; ++i) {
            int m;
            if (scanf("%d", &m) == -1) {
                return 0;
            }
            for (int j = 0; j < m; ++j) {
                int v;
                scanf("%d", &v);
                g[i][v - 1] = 1;
                g[v - 1][i] = 1;
            }
        }
        for (int k = 0; k < 20; ++k) {
            for (int i = 0; i < 20; ++i) {
                for (int j = 0; j < 20; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int n;
        scanf("%d", &n);
        printf("Test Set #%d\n", T);
        for (int i = 0; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%2d to %2d: %d\n", u, v, g[u - 1][v - 1]);
        }
        printf("\n");
    }
}
