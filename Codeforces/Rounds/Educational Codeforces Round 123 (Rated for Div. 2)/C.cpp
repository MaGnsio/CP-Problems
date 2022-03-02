/**
 *    author:  MaGnsi0
 *    created: 22.02.2022 16:56:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        vector<long long> c(n, LLONG_MIN);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                c[j - i] = max(c[j - i], (long long)(a[j] - (i ? a[i - 1] : 0)));
            }
        }
        for (int i = 0; i <= n; ++i) {
            long long ans = 0;
            for (int j = 0; j < n; ++j) {
                ans = max(ans, c[j] + 1LL * min(j + 1, i) * k);
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
