/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 02:22:06
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 1, -1, -1};
const int dy[4] = {1, -1, 1, -1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        string s;
        cin >> s;
        int j = (s == "DR" ? 0 : (s == "DL" ? 1 : (s == "UR" ? 2 : 3)));
        vector<vector<vector<int>>> bounces(n, vector<vector<int>>(m, vector<int>(4, -1)));
        queue<int> X, Y, Z;
        X.push(x1), Y.push(y1), Z.push(j);
        bounces[x1][y1][j] = 0;
        while (!X.empty()) {
            int x = X.front(); X.pop();
            int y = Y.front(); Y.pop();
            int z = Z.front(); Z.pop();
            int nx = x + dx[z];
            int ny = y + dy[z];
            int nz = z;
            int bounced = 0;
            if ((nx >= n || nx < 0) && (ny >= m || ny < 0)) {
                nz = (z == 0 ? 3 : (z == 3 ? 0 : (z == 1 ? 2 : 1)));
                nx = x + dx[nz];
                ny = y + dy[nz];
                bounced++;
            } else if (nx >= n || nx < 0) {
                nz = (z == 0 ? 2 : (z == 1 ? 3 : (z == 2 ? 0 : 1)));
                nx = x + dx[nz];
                ny = y + dy[nz];
                bounced++;
            } else if (ny >= m || ny < 0) {
                nz = (z == 0 ? 1 : (z == 1 ? 0 : (z == 2 ? 3 : 2)));
                nx = x + dx[nz];
                ny = y + dy[nz];
                bounced++;
            }
            if (bounces[nx][ny][nz] == -1) {
                X.push(nx), Y.push(ny), Z.push(nz);
                bounces[nx][ny][nz] = bounces[x][y][z] + bounced;
            }
        }
        int ans = -1;
        for (int i = 0; i < 4; ++i) {
            if (bounces[x2][y2][i] != -1 && (bounces[x2][y2][i] < ans || ans == -1)) {
                ans = bounces[x2][y2][i];
            }
        }
        cout << ans << "\n";
    }
}
