/**
 *    author:  MaGnsi0
 *    created: 14.12.2021 22:25:42
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
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 0; i < n - 2 * k; ++i) {
            res += a[i];
        }
        for (int i = n - 2 * k; i + k < n; ++i) {
            res += (a[i] == a[i + k]);
        }
        cout << res << "\n";
    }
}
