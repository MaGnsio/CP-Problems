/**
 *    author:  MaGnsi0
 *    created: 16.02.2023 20:44:45
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
            a[i]--;
        }
        vector<int> b(n, 0), c(n, 0);
        for (int i = 0; i < n; ++i) {
            c[a[i]]++;
        }
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int64_t sum = 0;
            c[a[i]]--;
            for (int j = i + 1; j < n; ++j) {
                c[a[j]]--;
                sum -= b[a[j]];
                if (a[i] == a[j]) {
                    ans += sum;
                }
                sum += b[a[j]];
                b[a[j]]++;
                sum -= (b[a[j]] - 1) * (c[a[j]] + 1);
                sum += b[a[j]] * c[a[j]];
            }
            for (int j = i + 1; j < n; ++j) {
                c[a[j]]++;
                b[a[j]]--;
            }
        }
        cout << ans << "\n";
    }
}
