/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 04:35:08
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
    int ans = 100, sum = 100;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ans = max(ans, sum);
    }
    cout << ans;
}
