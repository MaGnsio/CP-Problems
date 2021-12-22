/**
 *    author:  MaGnsi0
 *    created: 17.11.2021 01:51:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N = 202;
    map<char, int> mp;
    {
        mp['F'] = 0;
        mp['R'] = 1;
        mp['L'] = 2;
        mp['B'] = 3;
    }
    map<pair<int, int>, int> new_d;
    {
        new_d[{0, 0}] = 0, new_d[{0, 1}] = 3, new_d[{0, 2}] = 2, new_d[{0, 3}] = 1;
        new_d[{1, 0}] = 1, new_d[{1, 1}] = 2, new_d[{1, 2}] = 3, new_d[{1, 3}] = 0;
        new_d[{2, 0}] = 2, new_d[{2, 1}] = 0, new_d[{2, 2}] = 1, new_d[{2, 3}] = 3;
        new_d[{3, 0}] = 3, new_d[{3, 1}] = 1, new_d[{3, 2}] = 0, new_d[{3, 3}] = 2;
    }
    vector<vector<int>> dx(4, vector<int>(4)), dy(4, vector<int>(4));
    {
        dx[0][0] = 0, dx[0][1] = 1, dx[0][2] = -1, dx[0][3] = 0;
        dy[0][0] = 1, dy[0][1] = 0, dy[0][2] = 0, dy[0][3] = -1;
        dx[1][0] = 0, dx[1][1] = -1, dx[1][2] = 1, dx[1][3] = 0;
        dy[1][0] = -1, dy[1][1] = 0, dy[1][2] = 0, dy[1][3] = 1;
        dx[2][0] = -1, dx[2][1] = 0, dx[2][2] = 0, dx[2][3] = 1;
        dy[2][0] = 0, dy[2][1] = 1, dy[2][2] = -1, dy[2][3] = 0;
        dx[3][0] = 1, dx[3][1] = 0, dx[3][2] = 0, dx[3][3] = -1;
        dy[3][0] = 0, dy[3][1] = -1, dy[3][2] = 1, dy[3][3] = 0;
    }
    int T;
    cin >> T;
    cout << T << "\n";
    while (T--) {
        string s;
        cin >> s;
        vector<vector<char>> g(N, vector<char>(N, '#'));
        g[100][0] = '.';
        int x = 100, y = 0, d = 0;
        for (auto& c : s) {
            int nx = x + dx[d][mp[c]];
            int ny = y + dy[d][mp[c]];
            g[nx][ny] = '.';
            x = nx, y = ny, d = new_d[{d, mp[c]}];
        }
        int fr = N, fc = N, lr = 0, lc = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (g[i][j] == '.') {
                    fr = min(fr, i), fc = min(fc, j);
                    lr = max(lr, i), lc = max(lc, j);
                }
            }
        }
        fr--, lr++, lc++;
        cout << lr - fr + 1 << " " << lc - fc + 1 << "\n";
        for (int i = fr; i <= lr; ++i) {
            for (int j = fc; j <= lc; ++j) {
                cout << g[i][j];
            }
            cout << "\n";
        }
    }
}
