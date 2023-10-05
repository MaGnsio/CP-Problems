/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 15:39:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> L(26, vector<int>(n, m));
    vector<vector<int>> R(26, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            L[a[i][j] - 'a'][i] = min(L[a[i][j] - 'a'][i], j);
            R[a[i][j] - 'a'][i] = max(R[a[i][j] - 'a'][i], j);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int i; cin >> i; i--;
        int j; cin >> j; j--;
        int ans = 0;
        for (int k = 0; k < 26; ++k) {
            if (L[k][i] > R[k][i]) { continue; }
            if (L[k][j] > R[k][j]) { continue; }
            if (L[k][i] > R[k][j]) { continue; }
            if (L[k][j] > R[k][i]) { continue; }
            int low = max(L[k][i], L[k][j]);
            int high = min(R[k][i], R[k][j]);
            ans += high - low + 1;
        }
        cout << ans << "\n";
    }
}
