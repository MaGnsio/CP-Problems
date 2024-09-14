/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 15:22:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    a[0] = -2e9, a[n + 1] = 2e9;
    for (int i = 1; i < n + 2; ++i) {
        b[i] += b[i - 1];
    }
    int Q; cin >> Q;
    while (Q--) {
        int L; cin >> L;
        int R; cin >> R;
        L = lower_bound(a.begin(), a.end(), L) - a.begin() - 1;
        R = upper_bound(a.begin(), a.end(), R) - a.begin() - 1;
        cout << b[R] - b[L] << "\n";
    }
}
