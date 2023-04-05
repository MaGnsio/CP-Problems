/**
 *    author:  MaGnsi0
 *    created: 19.02.2023 14:00:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        ans += a[x - 1];
    }
    cout << ans;
}
