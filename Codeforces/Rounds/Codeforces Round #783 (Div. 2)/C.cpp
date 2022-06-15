/**
 *    author:  MaGnsi0
 *    created: 19.04.2022 16:28:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        int64_t cnt = 0;
        vector<int64_t> b(n, 0);
        for (int j = i + 1; j < n; ++j) {
            if (b[j - 1] <= 0) {
                b[j] = a[j];
                cnt++;
                continue;
            }
            int64_t x = (b[j - 1] + a[j] - 1) / a[j];
            x += (x * a[j] == b[j - 1]);
            b[j] = x * a[j];
            cnt += x;
        }
        for (int j = i - 1; j >= 0; --j) {
            if (b[j + 1] >= 0) {
                b[j] = -1 * a[j];
                cnt++;
                continue;
            }
            int64_t x = (abs(b[j + 1]) + a[j] - 1) / a[j];
            x += (x * a[j] == abs(b[j + 1]));
            b[j] = -1 * x * a[j];
            cnt += x;
        }
        ans = min(ans, cnt);
    }
    cout << ans;
}
