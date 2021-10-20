/**
 *    author:  MaGnsi0
 *    created: 17/07/2021 13:36:27
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k;
    cin >> n >> k;
    if (n * n < k) {
        cout << -1;
        return 0;
    }
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i][j]) {
                continue;
            }
            if (!k) {
                break;
            }
            if (i == j) {
                if ((i - 1 != n - 1) || (k & 1)) {
                    v[i][j] = 1;
                    k--;
                }
            } else {
                if (k >= 2) {
                    v[i][j] = v[j][i] = 1;
                    k -= 2;
                }
            }
        }
        if (!k) {
            break;
        }
    }
    if (k) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
