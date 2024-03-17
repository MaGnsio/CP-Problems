/**
 *    author:  MaGnsi0
 *    created: 10.12.2023 14:12:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int H; cin >> H;
    int W; cin >> W;
    vector<vector<int>> a(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> b[i][j];
        }
    }
    int ans = INT_MAX;
    vector<int> rows(H);
    iota(rows.begin(), rows.end(), 0);
    do {
        vector<int> cols(W);
        iota(cols.begin(), cols.end(), 0);
        do {
            vector<vector<int>> c(H, vector<int>(W));
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < W; ++j) {
                    c[i][j] = a[rows[i]][cols[j]];
                }
            }
            if (c != b) { continue; }
            int op = 0;
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < i; ++j) {
                    op += rows[i] < rows[j];
                }
            }
            for (int i = 0; i < W; ++i) {
                for (int j = 0; j < i; ++j) {
                    op += cols[i] < cols[j];
                }
            }
            ans = min(ans, op);
        } while (next_permutation(cols.begin(), cols.end()));
    } while (next_permutation(rows.begin(), rows.end()));
    cout << (ans == INT_MAX ? -1 : ans);
}
