/**
 *    author:  MaGnsi0
 *    created: 05.01.2025 01:43:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        int x = min(a[i] / b[i], k);
        ans[i] = x; k -= x;
    }
    if (k) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
    } else {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
    }
}
