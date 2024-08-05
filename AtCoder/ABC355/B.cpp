/**
 *    author:  MaGnsi0
 *    created: 25.05.2024 15:03:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<bool> in_a(202, false);
    vector<int> c(n + m);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        in_a[c[i]] = true;
    }
    for (int i = n; i < n + m; ++i) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    bool ok = false;
    for (int i = 1; i < n + m; ++i) {
        ok |= in_a[c[i - 1]] && in_a[c[i]];
    }
    cout << (ok ? "Yes" : "No");
}
