/**
 *    author:  MaGnsi0
 *    created: 11.04.2022 06:01:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ok = [&](int m) {
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = (a[i] >= m ? 1 : -1);
        }
        for (int i = 1; i < n; ++i) {
            b[i] += b[i - 1];
        }
        vector<int> c = b;
        for (int i = 1; i < n; ++i) {
            c[i] = min({0, c[i], c[i - 1]});
        }
        for (int i = k - 1; i < n; ++i) {
            int x = b[i] - (i >= k ? c[i - k] : 0);
            if (x > 0) {
                return true;
            }
        }
        return false;
    };
    int l = 1, r = n, ans;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ok(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans;
}
