/**
 *    author:  MaGnsi0
 *    created: 27.12.2021 16:26:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        long long sum = 0;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end(), greater<long long>());
        auto ok = [&](long long m) {
            long long nsum = sum - max(m - (n - 1), 0LL);
            long long mini = a[n - 1] - max(m - (n - 1), 0LL);
            m -= max(m - (n - 1), 0LL);
            assert(m <= n - 1);
            long long diff_sum = 0;
            vector<long long> diff(m);
            for (int i = 0; i < m; ++i) {
                diff[i] = (a[i] - mini);
                diff_sum += diff[i];
            }
            if (nsum - diff_sum <= k) {
                return true;
            }
            for (int i = m - 1; i >= 0; --i) {
                diff_sum -= diff[i];
                diff_sum += i - (m - 1 - i);
                nsum--;
                if (nsum - diff_sum <= k) {
                    return true;
                }
            }
            return false;
        };
        long long l = 0, r = 2e16, res = -1;
        while (l <= r) {
            long long m = (r + l) / 2;
            if (ok(m)) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        assert(res != -1);
        cout << res << "\n";
    }
}
