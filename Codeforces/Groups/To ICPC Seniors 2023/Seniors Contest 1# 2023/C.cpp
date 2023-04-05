/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 09:24:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int ans = 10 * a[0] + a[1];
    cout << ans;
}
