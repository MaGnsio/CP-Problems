/**
 *    author:  MaGnsi0
 *    created: 11/06/2021 21:36:43
**/
#include <bits/stdc++.h>
using namespace std;

int n;
int g[10][10][4];

int count () {
    int res = 0;
    for (int x = 0; x < n - 1; ++x) {
        for (int y = 0; y < n - 1; ++y) {
            res += (g[x][y][3] + g[x][y][1] + g[x + 1][y + 1][2] + g[x + 1][y + 1][0] == 4);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n;
    int cur = 0, a = 0, b = 0;
    bool turn = 0;
    string s = "";
    memset(g, 0, sizeof g);
    for (int i = 0; i < 2 * n * (n - 1); ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        // 0 up, 1 down, 2 left, 3 right
        if (x1 == x2) {
            if (y1 < y2) {
                g[x1][y1][3] = 1;
                g[x2][y2][2] = 1;
            } else {
                g[x1][y1][2] = 1;
                g[x2][y2][3] = 1;
            }
        } else {
            if (x1 < x2) {
                g[x1][y1][1] = 1;
                g[x2][y2][0] = 1;
            } else {
                g[x1][y1][0] = 1;
                g[x2][y2][1] = 1;
            }
        }
        s += (turn ? "B" : "A");
        int total = count();
        if (total - cur > 0) {
            a += (!turn ? total - cur : 0);
            b += (turn ? total - cur : 0);
            cur = total;
        } else {
            turn ^= 1;
        }
    }
    cout << s << "\n" << a << " " << b;
}
