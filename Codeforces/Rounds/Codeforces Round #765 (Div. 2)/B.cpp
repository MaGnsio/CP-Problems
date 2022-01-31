/**
 *    author:  MaGnsi0
 *    created: 12.01.2022 13:57:15
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 15e4 + 15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> f(N);
        for (int i = 0; i < n; ++i) {
            f[a[i]].push_back(i);
        }
        int res = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < (int)f[i].size(); ++j) {
                res = max(res, n - f[i][j] + f[i][j - 1]);
            }
        }
        cout << res << "\n";
    }
}
