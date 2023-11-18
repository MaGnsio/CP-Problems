/**
 *    author:  MaGnsi0
 *    created: 11.10.2023 20:50:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n, n), b(n, n);
    for (int i = 0; i < m; ++i) {
        int x; cin >> x; a[x - 1]--;
        int y; cin >> y; b[y - 1]--;
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!a[i] || !b[i]) { break; }
        ans = i + 1;
    }
    cout << ans;
}
