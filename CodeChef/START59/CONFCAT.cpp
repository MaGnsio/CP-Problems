/**
 *    author:  MaGnsi0
 *    created: 05.10.2022 16:43:23
**/
#include <bits/stdc++.h>

using namespace std;

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
        int maxa = *max_element(a.begin(), a.end());
        if (maxa == a[0]) {
            cout << -1 << "\n";
            continue;
        }
        vector<vector<int>> ans(2);
        for (int i = 0, j = 0; i < n; ++i) {
            if (a[i] == maxa) {
                j = 1;
            }
            ans[j].push_back(a[i]);
        }
        int m = (int)ans[0].size(), k = (int)ans[1].size();
        cout << m << "\n";
        for (int i = 0; i < m; ++i) {
            cout << ans[0][i] << " ";
        }
        cout << "\n" << k << "\n";
        for (int i = 0; i < k; ++i) {
            cout << ans[1][i] << " ";
        }
        cout << "\n";
    }
}
