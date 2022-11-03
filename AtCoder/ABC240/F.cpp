/**
 *    author:  MaGnsi0
 *    created: 23.02.2022 01:32:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<long long> x(n), y(n), s(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            s[i] = x[i] * y[i];
        }
        for (int i = 1; i < n; ++i) {
            s[i] += s[i - 1];
        }
        long long sum = 0, ans = LLONG_MIN;
        auto F = [&](int k, int i) {
            long long res = sum;
            if (i) {
                res += k * s[i - 1];
            }
            res += x[i] * k * (k + 1) / 2;
            return res;
        };
        for (int i = 0; i < n; ++i) {
            if (x[i] < 0) {
                long long l = 0, r = y[i];
                while (r - l >= 5) {
                    long long mid = (l + r) / 2;
                    if (F(mid, i) < F(mid + 1, i)) {
                        l = mid;
                    } else {
                        r = mid + 1;
                    }
                }
                for (int j = l + 1; j < r + 1; ++j) {
                    ans = max(ans, F(j, i));
                }
            }
            sum = F(y[i], i);
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
}
