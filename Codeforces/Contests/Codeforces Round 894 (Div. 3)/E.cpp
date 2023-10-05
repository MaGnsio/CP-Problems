/**
 *    author:  MaGnsi0
 *    created: 24.08.2023 18:19:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m, d;
        cin >> n >> m >> d;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 0, sum = 0;
        multiset<int64_t> S;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, sum + a[i] - d * (i + 1));
            if (m == 1) { continue; }
            if ((int)S.size() == m - 1) {
                if (a[i] > *S.begin()) {
                    sum += a[i] - *S.begin();
                    S.erase(S.begin());
                    S.insert(a[i]);
                }
            } else if (a[i] > 0) {
                sum += a[i];
                S.insert(a[i]);
            }
        }
        cout << ans << "\n";
    }
}
