/**
 *    author:  MaGnsi0
 *    created: 06.08.2023 11:59:08
**/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int n, m, a[N], c[N][N];

void power(int p) {
    int res[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = (i == j ? 1 : 0);
        }
    }
    while (p) {
        if (p & 1) {
            int add[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    add[i][j] = 0;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        add[i][j] += res[i][k] * c[k][j];
                        add[i][j] %= 2;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    res[i][j] = add[i][j];
                }
            }
        }
        int new_c[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                new_c[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    new_c[i][j] += c[i][k] * c[k][j];
                    new_c[i][j] %= 2;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i][j] = new_c[i][j];
            }
        }
        p /= 2;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = res[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> c[j][i];
            }
            c[i][i] = 1;
        }
        power(m);
        int new_a[n];
        for (int i = 0; i < n; ++i) {
            new_a[i] = 0;
        }
        for (int i = 0; i < 1; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    new_a[j] += a[k] * c[k][j];
                    new_a[j] %= 2;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            a[i] = new_a[i];
        }
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) { continue; }
            k += b[i];
        }
        cout << (k % n) + 1 << "\n";
    }
}
