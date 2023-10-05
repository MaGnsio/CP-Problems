/**
 *    author:  MaGnsi0
 *    created: 05.05.2023 17:47:59
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (a[i] == a[n - i - 1]) { continue; }
            if (a[i] < a[n - i - 1]) { swap(a[i], a[n - i - 1]); }
            ans = __gcd(ans, a[i] - a[n - i - 1]);
        }
        cout << ans << "\n";
    }
}
