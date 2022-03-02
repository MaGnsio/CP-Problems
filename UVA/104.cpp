/**
 *    author:  MaGnsi0
 *    created: 11.02.2022 01:54:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while (cin >> n) {
        int p[n][n][n];
        double d[n][n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    d[i][j][0] = 1.0;
                } else {
                    cin >> d[i][j][0];
                }
                p[i][j][0] = i;
            }
        }
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j][k] = 0.0;
                    p[i][j][k] = -1;
                }
            }
        }
        for (int exchange = 1; exchange < n; ++exchange) {
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (d[i][k][exchange - 1] * d[k][j][0] > d[i][j][exchange]) {
                            d[i][j][exchange] = d[i][k][exchange - 1] * d[k][j][0];
                            p[i][j][exchange] = k;
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                if (d[i][i][exchange] > 1.01) {
                    int x = i;
                    stack<int> s;
                    while (exchange - 1 >= 0) {
                        s.push(x = p[i][x][exchange--]);
                    }
                    cout << i + 1 << " ";
                    while (!s.empty()) {
                        cout << s.top() + 1 << " ";
                        s.pop();
                    }
                    cout << i + 1 << "\n";
                    goto profit;
                }
            }
        }
        cout << "no arbitrage sequence exists\n";
        profit:;
    }
}
