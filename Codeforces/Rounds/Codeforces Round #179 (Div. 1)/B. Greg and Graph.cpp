/**
 *    author:  MaGnsi0
 *    created: 21/06/2021 03:06:08
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }
    vector<int> v(n), ans;
    for (int i = n - 1; i >= 0; --i) {
        cin >> v[i];
        v[i]--;
    }
    vector<bool> visited(n, false);
    for (auto& k : v) {
        int res = 0;
        visited[k] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                res += d[i][j] * (visited[i] & visited[j]);
            }
        }
        ans.push_back(res);
    }
    for (int i = n - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
}
