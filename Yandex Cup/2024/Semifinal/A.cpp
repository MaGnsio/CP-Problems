/**
 *    author:  MaGnsi0
 *    created: 03.11.2024 16:04:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - (i + 1));
        ans += abs(b[i] - (i + 1));
    }
    cout << ans;
}
