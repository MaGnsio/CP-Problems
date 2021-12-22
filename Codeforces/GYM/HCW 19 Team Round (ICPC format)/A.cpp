/**
 *    author:  MaGnsi0
 *    created: 05.11.2021 18:46:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<vector<int>> a(n + 2, vector<int>(3, 0));
    vector<int> cur(3, 1);
    for (int i = 0; i < 2 * n + 5; ++i) {
        int nx = cur[0] + x;
        if (nx > n + 1) {
            nx -= n + 1;
        }
        if ((nx != 1) && (a[nx][1] == 1 || a[nx][2] == 1)) {
            cout << 3 * i + 1;
            return 0;
        } else {
            cur[0] = nx;
            a[nx][0] = 1;
        }
        int ny = cur[1] + y;
        if (ny > n + 1) {
            ny -= n + 1;
        }
        if ((ny != 1) && (a[ny][0] == 1 || a[ny][2] == 1)) {
            cout << 3 * i + 2;
            return 0;
        } else {
            cur[1] = ny;
            a[ny][1] = 1;
        }
        int nz = cur[2] + z;
        if (nz > n + 1) {
            nz -= n + 1;
        }
        if ((nz != 1) && (a[nz][0] == 1 || a[nz][1] == 1)) {
            cout << 3 * i + 3;
            return 0;
        } else {
            cur[2] = nz;
            a[nz][2] = 1;
        }
    }
    cout << "3000000000";
}
