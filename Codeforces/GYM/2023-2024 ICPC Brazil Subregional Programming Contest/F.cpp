/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 16:50:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int64_t X;
    cin >> X >> n >> m;
    int ans = m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int64_t x; cin >> x;
        X += x;
    }
    for (int i = 0; i < n; ++i) {
        if (X >= a[i]) {
            ans++;
            X -= a[i];
        } else {
            break;
        }
    }
    cout << ans;
}
