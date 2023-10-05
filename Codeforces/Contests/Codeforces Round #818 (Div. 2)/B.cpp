/**
 *    author:  MaGnsi0
 *    created: 02.09.2022 16:33:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        vector<vector<char>> a(n, vector<char>(n, '.'));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<int> X, Y;
        X.push(r - 1), Y.push(c - 1);
        visited[r - 1][c - 1] = true;
        while (!X.empty()) {
            int x = X.front(), y = Y.front();
            X.pop(), Y.pop();
            a[x][y] = 'X';
            if (x + k < n && !visited[x + k][y]) {
                X.push(x + k), Y.push(y);
                visited[x + k][y] = true;
            }
            if (x - k >= 0 && !visited[x - k][y]) {
                X.push(x - k), Y.push(y);
                visited[x - k][y] = true;
            }
            if (y + k < n && !visited[x][y + k]) {
                X.push(x), Y.push(y + k);
                visited[x][y + k] = true;
            }
            if (y - k >= 0 && !visited[x][y - k]) {
                X.push(x), Y.push(y - k);
                visited[x][y - k] = true;
            }
            if (!visited[(x + 1) % n][(y + 1) % n]) {
                X.push((x + 1) % n), Y.push((y + 1) % n);
                visited[(x + 1) % n][(y + 1) % n] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
}
