/**
 *    author:  MaGnsi0
 *    created: 04.07.2022 16:34:10
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
        vector<vector<int>> unit = {{1, 0}, {0, 1}}; 
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j += 2) {
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        a[i + k][j + l] = unit[k][l];
                    }
                }
                swap(unit[0], unit[1]);
            }
            if ((m / 2) % 2 == 0) {
                swap(unit[0], unit[1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
