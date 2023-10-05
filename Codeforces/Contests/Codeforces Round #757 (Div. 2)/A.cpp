/**
 *    author:  MaGnsi0
 *    created: 26.11.2021 13:02:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= l && a[i] <= r && a[i] <= k) {
                res++;
                k -= a[i];
            }
        }
        cout << res << "\n";
    }
}
