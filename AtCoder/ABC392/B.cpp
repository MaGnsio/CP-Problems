/**
 *    author:  MaGnsi0
 *    created: 08.02.2025 14:01:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<bool> a(n + 1);
    for (int i = 0; i < m; ++i) {
        int x; cin >> x; a[x] = true;
    }
    cout << n - m << "\n";
    for (int i = 1; i <= n; ++i) {
        if (a[i]) { continue; }
        cout << i << " ";
    }
}
