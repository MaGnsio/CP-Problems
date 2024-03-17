/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 22:18:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> b(n), c(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i] += a[i][j] == 'o';
            c[j] += a[i][j] == 'o';
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'x') { continue; }
            ans += (b[i] - 1) * (c[j] - 1);
        }
    }
    cout << ans;
}
