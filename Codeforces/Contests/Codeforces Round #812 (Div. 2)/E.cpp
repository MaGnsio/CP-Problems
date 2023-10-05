/**
 *    author:  MaGnsi0
 *    created: 10.08.2022 08:00:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }
        vector<int> p(n + 1);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (x < 0) {
                return -find(-x);
            } else if (x == p[x]) {
                return x;
            } else {
                return p[x] = find(p[x]);
            }
        };
        function<void(int, int)> unite = [&](int x, int y) {
            x = find(x), y = find(y);
            if (abs(x) == abs(y)) {
                return;
            }
            if (x > 0) {
                p[x] = y;
            } else {
                p[-x] = -y;
            }
        };
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] < a[j][i]) {
                    unite(i, j);
                }
                if (a[i][j] > a[j][i]) {
                    unite(i, -j);
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (find(i) < 0) {
                continue;
            }
            for (int j = 1; j <= n; ++j) {
                swap(a[i][j], a[j][i]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
