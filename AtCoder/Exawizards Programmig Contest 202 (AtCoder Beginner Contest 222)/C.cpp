/**
 *    author:  MaGnsi0
 *    created: 14.10.2021 14:31:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(2 * n, vector<char>(m));
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    vector<pair<int, int>> rank(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        rank[i] = {0, i};
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < 2 * n; i += 2) {
            int player_1 = rank[i].second;
            int player_2 = rank[i + 1].second;
            if (g[player_1][j] == g[player_2][j]) {
                continue;
            }
            if ((g[player_1][j] == 'G' && g[player_2][j] == 'C')
              ||(g[player_1][j] == 'C' && g[player_2][j] == 'P')
              ||(g[player_1][j] == 'P' && g[player_2][j] == 'G')) {
                rank[i].first++;
            } else {
                rank[i + 1].first++;
            }
        }
        sort(rank.begin(), rank.end(), [](pair<int, int> a, pair<int, int> b) {
                return ((a.first > b.first) || (a.first == b.first && a.second < b.second));
           });
    }
    for (int i = 0; i < 2 * n; ++i) {
        cout << rank[i].second + 1 << "\n";
    }
}
