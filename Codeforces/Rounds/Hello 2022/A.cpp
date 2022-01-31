/**
 *    author:  MaGnsi0
 *    created: 03.01.2022 16:27:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<char>> a(n, vector<char>(n, '.'));
        int x = 0;
        while (x < n && k) {
            a[x][x] = 'R';
            x += 2;
            k--;
        }
        if (k) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << a[i][j];
                }
                cout << "\n";
            }
        }
    }
}
