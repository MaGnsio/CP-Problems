/**
 *    author:  MaGnsi0
 *    created: 02.01.2022 18:48:22
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
        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
        }
        vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < n; ++i) {
            a[l[i]][r[i]] = true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = l[i]; j <= r[i]; ++j) {
                if ((j == l[i] || a[l[i]][j - 1]) && (j == r[i] || a[j + 1][r[i]])) {
                    cout << l[i] << " " << r[i] << " " << j << "\n";
                }
            }
        }
    }
}
