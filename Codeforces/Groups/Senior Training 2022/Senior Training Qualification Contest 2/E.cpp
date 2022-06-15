/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 19:47:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("downloader.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = k - 1 + n % k; i < n; i += k) {
        ans += a[i];
    }
    if (n % k) {
        ans += a[n % k - 1];
    }
    cout << ans;
}
