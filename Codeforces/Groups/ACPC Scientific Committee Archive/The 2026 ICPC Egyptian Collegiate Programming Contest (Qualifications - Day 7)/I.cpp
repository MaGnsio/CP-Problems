/**
 *    author:  MaGnsi0
 *    created: 19.08.2026 19:58:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, abs(a[i] - a[i - 1]));
    }
    cout << ans;
}
