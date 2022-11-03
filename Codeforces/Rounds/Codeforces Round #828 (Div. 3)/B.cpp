/**
 *    author:  MaGnsi0
 *    created: 31.10.2022 19:00:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t sum_even = 0, sum_odd = 0;
        int64_t cnt_even = 0, cnt_odd = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] & 1) {
                sum_odd += a[i];
                cnt_odd += 1;
            } else {
                sum_even += a[i];
                cnt_even += 1;
            }
        }
        for (int i = 0; i < q; ++i) {
            int t, x;
            cin >> t >> x;
            if (t == 0) {
                if (x & 1) {
                    sum_odd += sum_even;
                    sum_odd += cnt_even * x;
                    cnt_odd += cnt_even;
                    sum_even = 0;
                    cnt_even = 0;
                } else {
                    sum_even += cnt_even * x;
                }
            } else {
                if (x & 1) {
                    sum_even += sum_odd;
                    sum_even += cnt_odd * x;
                    cnt_even += cnt_odd;
                    sum_odd = 0;
                    cnt_odd = 0;
                } else {
                    sum_odd += cnt_odd * x;
                }
            }
            cout << sum_even + sum_odd << "\n";
        }
    }
}
