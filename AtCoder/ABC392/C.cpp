/**
 *    author:  MaGnsi0
 *    created: 08.02.2025 14:06:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n), ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; b[i]--;
    }
    for (int i = 0; i < n; ++i) {
        int j = b[i];
        ans[j] = b[a[i]] + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
