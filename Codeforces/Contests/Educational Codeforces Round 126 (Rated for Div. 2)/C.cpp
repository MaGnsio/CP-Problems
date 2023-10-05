/**
 *    author:  MaGnsi0
 *    created: 09.04.2022 16:27:51
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        function<int64_t(vector<int64_t>, int)> F = [](vector<int64_t> a, int x) {
            int n = (int)a.size();
            for (int i = 0; i < n; ++i) {
                a[i] = (a[n - 1] + x) - a[i];
            }
            int64_t ans = 0, cntOdd = 0;
            for (int i = 0; i < n; ++i) {
                cntOdd += (a[i] % 2 != 0);
                a[i] -= (a[i] % 2);
            }
            if (cntOdd) {
                ans += (2 * (cntOdd--) - 1);
                for (int i = 0; i < n; ++i) {
                    int64_t x = min(cntOdd, a[i] / 2);
                    a[i] -= 2LL * x;
                    cntOdd -= x;
                }
                long long R = accumulate(a.begin(), a.end(), 0LL);
                return ans + min(2 * ((R + 2) / 3), 2 * ((R + 3) / 3) - 1);
            } else {
                long long R = accumulate(a.begin(), a.end(), 0LL);
                return ans + min(2 * ((R + 2) / 3), 2 * ((R + 1) / 3) + 1);
            }

        };
        cout << min(F(a, 0), F(a, 1)) << "\n";
    }
}
