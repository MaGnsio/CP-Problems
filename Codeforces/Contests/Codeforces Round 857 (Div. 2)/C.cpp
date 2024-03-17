/**
 *    author:  MaGnsi0
 *    created: 02.01.2024 20:47:09
**/
#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 10);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int64_t>> a(N, vector<int64_t>(N));
    for (int i = 0, color = 0; i < N; i += 2) {
        for (int j = 0; j < N; j += 2) {
            a[i][j] = color;
            a[i + 1][j] = color + 1;
            a[i][j + 1] = color + 2;
            a[i + 1][j + 1] = color + 3;
            color += 4;
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int color = 0;
        cout << n * m << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
