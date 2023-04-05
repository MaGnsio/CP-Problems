/**
 *    author:  MaGnsi0
 *    created: 07.02.2023 18:40:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("equal.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    function<int(int)> F = [&](int x) {
        int cnt = 0;
        while (x) {
            cnt += x % m;
            x /= m;
        }
        return cnt;
    };
    sort(a.begin(), a.end());
    int ans = 1e7;
    for (int i = 0; i <= 10000; ++i) {
        int ops = 0;
        for (int j = 0; j < n; ++j) {
            ops += F(a[n - 1] - a[j] + i);
        }
        ans = min(ans, ops);
    }
    cout << ans;
}
