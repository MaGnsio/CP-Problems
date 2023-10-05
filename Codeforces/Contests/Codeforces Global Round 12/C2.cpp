/**
 *    author:  MaGnsi0
 *    created: 14.04.2022 07:20:36
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
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int Tokens = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                Tokens += (a[i][j] == 'X');
                Tokens += (a[i][j] == 'O');
            }
        }
        Tokens /= 3;
        auto F = [](int n, vector<string> a, int x, char c) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = ((i + x) % 3); j < n; j += 3) {
                    if (a[i][j] == c) {
                        cnt++;
                    }
                }
            }
            return cnt;
        };
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                if (y == x || F(n, a, x, 'X') + F(n, a, y, 'O') > Tokens) {
                    continue;
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = ((i + x) % 3); j < n; j += 3) {
                        if (a[i][j] == 'X') {
                            a[i][j] = 'O';
                        }
                    }
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = ((i + y) % 3); j < n; j += 3) {
                        if (a[i][j] == 'O') {
                            a[i][j] = 'X';
                        }
                    }
                }
                goto print;
            }
        }
        print:
        for (int i = 0; i < n; ++i) {
            cout << a[i] << "\n";
        }
    }
}
