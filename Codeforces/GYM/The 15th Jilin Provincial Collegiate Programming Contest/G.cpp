/**
 *    author:  MaGnsi0
 *    created: 01.08.2022 02:41:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(2, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }
    while (true) {
        bool changes = false;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            vector<int> c;
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == -1) {
                    c.push_back(j);
                    continue;
                }
                cnt += a[i][j];
            }
            if (c.size() != 1) {
                continue;
            }
            changes = true;
            if ((b[0][i] == 0 && cnt & 1) || (b[0][i] == 1 && cnt % 2 == 0)) {
                a[i][c[0]] = 1;
            } else {
                a[i][c[0]] = 0;
            }
        }
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            vector<int> c;
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == -1) {
                    c.push_back(i);
                    continue;
                }
                cnt += a[i][j];
            }
            if (c.size() != 1) {
                continue;
            }
            changes = true;
            if ((b[1][j] == 0 && cnt & 1) || (b[1][j] == 1 && cnt % 2 == 0)) {
                a[c[0]][j] = 1;
            } else {
                a[c[0]][j] = 0;
            }
        }
        if (!changes) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (count(a[i].begin(), a[i].end(), -1)) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
