//https://www.e-olymp.com/en/contests/8063/problems/67698
#include <bits/stdc++.h>
using namespace std;

int flood_fill(vector<vector<int>>& G, int x, int y) {
    if (x < 0 || x >= 400) {
        return 0;
    }
    if (y < 0 || y >= 600) {
        return 0;
    }
    if (!G[x][y]) {
        return 0;
    }
    G[x][y] = 0;
    return (1 + flood_fill(G, x - 1, y) + flood_fill(G, x + 1, y) + flood_fill(G, x, y - 1) + flood_fill(G, x, y + 1));
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    while (cin >> N) {
        vector<vector<int>> G(400, vector<int>(600, 1));
        while (N--) {
            int X1, Y1, X2, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2;
            for (int i = X1; i <= X2; ++i) {
                for (int j = Y1; j <= Y2; ++j) {
                    G[i][j] = 0;
                }
            }
        }
        vector<int> A;
        for (int i = 0; i < 400; ++i) {
            for (int j = 0; j < 600; ++j) {
                if (G[i][j]) {
                    A.push_back(flood_fill(G, i, j));
                }
            }
        }
        sort(A.begin(), A.end());
        for (auto& x : A) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
