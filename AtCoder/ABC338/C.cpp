/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 14:05:03
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    int64_t ans = 0;
    for (int64_t x = 0; x < N; ++x) {
        bool canX = true;
        int64_t y = N;
        for (int i = 0; i < n; ++i) {
            canX = canX && x * b[i] <= a[i];
            if (c[i] == 0) { continue; }
            y = min(y, (a[i] - x * b[i]) / c[i]);
        }
        if (!canX) { continue; }
        ans = max(ans, x + y);
    }
    cout << ans;
}
