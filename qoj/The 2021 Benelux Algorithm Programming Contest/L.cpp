/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 22:17:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int64_t x; cin >> x;
            a[i] += x;
        }
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int64_t ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        ans = max(ans, a[n - 1] - a[n - i - 2] - a[i]);
    }
    cout << ans / 2;
}
