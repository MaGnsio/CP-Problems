/**
 *    author:  MaGnsi0
 *    created: 20.10.2022 16:40:00
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
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        int64_t ans = accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL) - b.back();
        cout << ans << "\n";
    }
}
