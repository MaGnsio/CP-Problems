/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 02:07:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int g = 0;
    for (int i = 0; i < m; ++i) {
        g = __gcd(g, b[i]);
    }
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        ok = ok && (a[i] - a[i - 1]) % g == 0;
    }
    cout << (ok ? "Yes" : "No");
}
