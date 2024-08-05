/**
 *    author:  MaGnsi0
 *    created: 01.06.2024 15:02:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x; a[j] -= x;
        }
    }
    bool ok = true;
    for (int i = 0; i < m; ++i) {
        ok = ok && a[i] <= 0;
    }
    cout << (ok ? "Yes" : "No");
}
