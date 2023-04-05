/**
 *    author:  MaGnsi0
 *    created: 03.02.2023 17:57:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<pair<int64_t, int>> b(n);
        for (int i = 0; i < n; ++i) {
            b[i].first = min(a[i] + n - i, a[i] + i + 1);
            b[i].second = i;
        }
        sort(b.begin(), b.end());
        for (int i = 1; i < n; ++i) {
            b[i].first += b[i - 1].first;
        }
        vector<int> I(n);
        for (int i = 0; i < n; ++i) {
            I[b[i].second] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] + i + 1 <= c) {
                ans = max(ans, 1);
            }
            int l = 0, r = n - 1, cnt = 0;
            while (l <= r) {
                int m = (l + r) / 2;
                int64_t sum = b[m].first + a[i] + i + 1;
                if (m >= I[i]) {
                    sum -= b[I[i]].first - (I[i] ? b[I[i] - 1].first : 0);
                }
                if (sum <= c) {
                    cnt = m + 1 + (m < I[i]);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
}
