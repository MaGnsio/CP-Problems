/**
 *    author:  MaGnsi0
 *    created: 22.06.2024 15:03:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i + 1 < 2 * n; ++i) {
        ans += a[i - 1] == a[i + 1];
    }
    cout << ans;
}
