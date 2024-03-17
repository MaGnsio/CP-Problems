/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 21:40:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    int ans = 0;
    for (int i = n - 1; i; i = a[i]) {
        ans++;
    }
    cout << ans;
}
