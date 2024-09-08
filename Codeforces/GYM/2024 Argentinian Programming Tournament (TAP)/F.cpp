/**
 *    author:  MaGnsi0
 *    created: 08.09.2024 17:17:34
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
    for (int i = 0; i < n; ++i) {
        ans += (a[i] == 1 ? 1 : -1);
    }
    for (int i = 2; i < n; ++i) {
        ans += (a[i - 2] + a[i - 1] + a[i] == 3);
    }
    cout << ans;
}
