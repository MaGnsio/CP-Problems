/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 19:26:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    while (Q--) {
        int64_t x; cin >> x;
        if (x == 0) {
            cout << 0 << "\n";
            continue;
        }
        int ans = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << (ans == n ? -1 : ans + 1) << "\n";
    }
}
