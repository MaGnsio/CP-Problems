/**
 *    author:  MaGnsi0
 *    created: 11.12.2021 13:52:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        int l = 0, r = n - 1, res = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] >= x) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << n - res << "\n";
    }
}
