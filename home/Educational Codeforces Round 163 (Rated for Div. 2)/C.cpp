/**
 *    author:  MaGnsi0
 *    created: 29.05.2024 22:02:03
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<string> a(2);
        for (int i = 0; i < 2; ++i) {
            cin >> a[i];
        }
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        queue<int> X, Y;
        X.push(0), Y.push(0), visited[0][0] = true;
        while (!X.empty()) {
            int x = X.front(); X.pop();
            int y = Y.front(); Y.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= 2) { continue; }
                if (ny < 0 || ny >= n) { continue; }
                if (a[nx][ny] == '<') {
                    ny--;
                } else {
                    ny++;
                }
                if (visited[nx][ny]) { continue; }
                X.push(nx), Y.push(ny), visited[nx][ny] = true;
            }
        }
        cout << (visited[1][n - 1] ? "YES" : "NO") << "\n";
    }
}
