/**
 *    author:  MaGnsi0
 *    created: 04.08.2024 16:12:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; b[i]--;
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        int r = a[i];
        for (int j = n - i - 1; j < n; ++j) {
            ans[r][b[j]] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
