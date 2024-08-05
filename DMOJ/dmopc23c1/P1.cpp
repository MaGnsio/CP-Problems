/**
 *    author:  MaGnsi0
 *    created: 23.03.2024 20:41:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    if (k > n) {
        cout << -1;
        return 0;
    }
    int x = n * n;
    vector<vector<int>> ans(n, vector<int>(n, -1)); 
    for (int i = 0; k; ++i, --k) {
        ans[i][i] = x--;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] != -1) { continue; }
            ans[i][j] = x--;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
