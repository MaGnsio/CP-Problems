/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 20:04:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (Q--) {
        int t; cin >> t;
        int r = lower_bound(a.begin(), a.end(), n - t) - a.begin();
        int l = upper_bound(a.begin(), a.end(), t) - a.begin() - 1;
        if (l >= r) {
            cout << -1 << "\n";
        } else {
            cout << (l + 1) + (n - r) << "\n";
        }
    }
}
