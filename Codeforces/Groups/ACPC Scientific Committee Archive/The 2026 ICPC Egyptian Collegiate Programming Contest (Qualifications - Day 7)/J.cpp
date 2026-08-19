/**
 *    author:  MaGnsi0
 *    created: 19.08.2026 19:59:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t m; cin >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (m < a[i]) {
            cout << i;
            exit(0);
        }
        m -= a[i];
    }
    cout << n;
}
