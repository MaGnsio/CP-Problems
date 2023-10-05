/**
 *    author:  MaGnsi0
 *    created: 09.04.2022 16:27:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] < b[i]) {
                swap(a[i], b[i]);
            }
        }
        long long ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += 1LL * abs(a[i] - a[i - 1]);
            ans += 1LL * abs(b[i] - b[i - 1]);
        }
        cout << ans << "\n";
    }
}
