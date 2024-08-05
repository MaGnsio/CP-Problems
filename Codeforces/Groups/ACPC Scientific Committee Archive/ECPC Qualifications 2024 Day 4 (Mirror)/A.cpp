/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 15:06:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t v; cin >> v;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += b[i] <= v * a[i];
    }
    cout << ans;
}
