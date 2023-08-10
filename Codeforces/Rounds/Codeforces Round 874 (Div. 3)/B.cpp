/**
 *    author:  MaGnsi0
 *    created: 19.05.2023 17:39:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        vector<int> c(n);
        iota(c.begin(), c.end(), 0);
        sort(c.begin(), c.end(), [&](int i, int j) {
                return a[i] < a[j];
            });
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[c[i]] = b[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
