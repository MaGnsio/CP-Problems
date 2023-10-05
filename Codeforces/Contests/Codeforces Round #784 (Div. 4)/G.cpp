/**
 *    author:  MaGnsi0
 *    created: 22.04.2022 09:57:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[j][i] == 'o') {
                    int cnt = 0;
                    for (int k = j - 1; k >= 0; --k) {
                        if (a[k][i] == 'o') {
                            break;
                        }
                        cnt += a[k][i] == '*';
                    }
                    for (int k = j - 1, l = 0; k >= 0; --k, ++l) {
                        if (a[k][i] == 'o') {
                            break;
                        }
                        if (l < cnt) {
                            a[k][i] = '*';
                        } else {
                            a[k][i] = '.';
                        }
                    }
                } else if (j == n - 1) {
                    int cnt = 0;
                    for (int k = j; k >= 0; --k) {
                        if (a[k][i] == 'o') {
                            break;
                        }
                        cnt += a[k][i] == '*';
                    }
                    for (int k = j, l = 0; k >= 0; --k, ++l) {
                        if (a[k][i] == 'o') {
                            break;
                        }
                        if (l < cnt) {
                            a[k][i] = '*';
                        } else {
                            a[k][i] = '.';
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << "\n";
        }
        cout << "\n";
    }
}
