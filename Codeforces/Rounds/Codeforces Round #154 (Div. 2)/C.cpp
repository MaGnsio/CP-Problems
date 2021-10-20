/**
 *    author:  MaGnsi0
 *    created: 14/06/2021 02:54:45
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
        x++;
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> d(n, vector<int>(1e5 + 1, -1));
    queue<int> x, y;
    x.push(x1), y.push(y1);
    d[x1][y1] = 0;
    while (!x.empty()) {
        int r = x.front(), c = y.front();
        x.pop(), y.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (r == nr) {
                if (nc < 0 || nc >= v[nr]) {
                    continue;
                }
                if (d[nr][nc] != -1) {
                    continue;
                }
                x.push(nr), y.push(nc);
                d[nr][nc] = d[r][c] + 1;
            } else {
                if (nr < 0 || nr >= n) {
                    continue;
                }
                nc = min(nc, v[nr] - 1);
                if (d[nr][nc] != -1) {
                    continue;
                }
                x.push(nr), y.push(nc);
                d[nr][nc] = d[r][c] + 1;
            }
        }
    }
    cout << d[x2][y2];
}
