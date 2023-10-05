/**
 *    author:  MaGnsi0
 *    created: 16.01.2023 01:38:18
**/
#include <bits/stdc++.h>

using namespace std;

bool is_square(int64_t x) {
    int64_t sq = sqrt(x);
    if (sq * sq < x) { sq++; }
    if (sq * sq > x) { sq--; }
    return sq * sq == x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        function<int(int64_t)> F = [&](int64_t x) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += is_square(A[i] + x);
            }
            return cnt;
        };
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int64_t diff = A[j] - A[i];
                for (int64_t k = 1; k * k <= diff; ++k) {
                    if (diff % k) { continue; }
                    int64_t l = diff / k;
                    if (k % 2 != l % 2) { continue; }
                    int64_t a = (l + k) / 2;
                    int64_t b = (l - k) / 2;
                    assert(a * a - b * b == diff);
                    int64_t x = a * a - A[j];
                    if (x < 0) { continue; }
                    ans = max(ans, F(x));
                }
            }
        }
        cout << ans << "\n";
    }
}
