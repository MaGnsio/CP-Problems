/**
 *    author:  MaGnsi0
 *    created: 09.09.2023 23:21:21
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int64_t>> a(n, vector<int64_t>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            if (a[i][i] > 0) { bad = true; }
            a[i][i] = 0;
        }
        if (bad) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == -1 && a[j][i] != -1) {
                    a[i][j] = a[j][i];
                }
                if (a[i][j] != -1 && a[j][i] == -1) {
                    a[j][i] = a[i][j];
                }
                if (a[i][j] != a[j][i]) { bad = true; }
            }
        }
        if (bad) {
            cout << "NO\n";
            continue;
        }
        vector<vector<int64_t>> b(n, vector<int64_t>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                b[i][j] = (a[i][j] == -1 ? OO : a[i][j]);
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] != -1 && a[i][j] != b[i][j]) {
                    bad = true;
                }
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (b[i][j] > b[i][k] + b[k][j]) {
                        bad = true;
                    }
                }
            }
        }
        if (bad) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
