/**
 *    author:  MaGnsi0
 *    created: 11.04.2024 19:33:27
**/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int a[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        int D = __gcd(a[0][0], a[n - 1][m - 1]);
        vector<int> candidates;
        for (int x = 1; x * x <= D; ++x) {
            if (D % x == 0) {
                candidates.push_back(x);
                if (D != x * x) { candidates.push_back(D / x); }
            }
        }
        sort(candidates.rbegin(), candidates.rend());
        bool visited[n][m];
        for (int d : candidates) {
            vector<int> X, Y;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    visited[i][j] = false;
                }
            }
            X.push_back(0), Y.push_back(0); visited[0][0] = true;
            while (!X.empty()) {
                int x = X.back(); X.pop_back();
                int y = Y.back(); Y.pop_back();
                for (int i = 0; i < 2; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= n || ny >= m) { continue; }
                    if (visited[nx][ny]) { continue; }
                    if (a[nx][ny] % d) { continue; }
                    X.push_back(nx), Y.push_back(ny); visited[nx][ny] = true;
                }
                if (visited[n - 1][m - 1]) { break; }
            }
            if (visited[n - 1][m - 1]) {
                cout << d << "\n";
                break;
            }
        }
    }
}
