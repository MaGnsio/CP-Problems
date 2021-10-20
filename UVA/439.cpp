/**
 *    author:  MaGnsi0
 *    created: 14/06/2021 03:12:59
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    string a, b;
    while (cin >> a >> b) {
        int x1 = (a[0] - 'a'), y1 = (a[1] - '1');
        int x2 = (b[0] - 'a'), y2 = (b[1] - '1');
        vector<vector<int>> d(8, vector<int>(8, -1));
        queue<int> x, y;
        x.push(x1), y.push(y1);
        d[x1][y1] = 0;
        while (!x.empty()) {
            int r = x.front(), c = y.front();
            x.pop(), y.pop();
            for (int i = 0; i < 8; ++i) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr > 7) {
                    continue;
                }
                if (nc < 0 || nc > 7) {
                    continue;
                }
                if (d[nr][nc] != -1) {
                    continue;
                }
                x.push(nr), y.push(nc);
                d[nr][nc] = d[r][c] + 1;
            }
        }
        cout << "To get from " << a << " to " << b << " takes " << d[x2][y2] << " knight moves.\n";
    }
}
