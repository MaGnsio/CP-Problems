/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 15:02:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            cin >> a[i][j]; a[i][j]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = a[max(ans, i)][min(ans, i)];
    }
    cout << ans + 1;
}
