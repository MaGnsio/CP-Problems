/**
 *    author:  MaGnsi0
 *    created: 29.04.2022 14:38:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, a, r, m;
    cin >> n >> a >> r >> m;
    vector<int64_t> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    auto F = [=](int64_t x) {
        int64_t sum = accumulate(A.begin(), A.end(), int64_t(0));
        int64_t to_remove = max(sum - n * x, int64_t(0));
        int64_t to_add = max(n * x - sum, int64_t(0));
        int64_t ans = r * to_remove + a * to_add;
        vector<int64_t> B = A;
        for (int i = 0; i < n; ++i) {
            if (B[i] > x) {
                int64_t y = min(B[i] - x, to_remove);
                B[i] -= y;
                to_remove -= y;
            }
            if (B[i] < x) {
                int64_t y = min(x - B[i], to_add);
                B[i] += y;
                to_add -= y;
            }
        }
        for (int i = 0; i < n; ++i) {
            ans += max(B[i] - x, int64_t(0)) * min(r + a, m);
        }
        return ans;
    };
    int64_t L = 0, R = 2e9;
    while (R - L >= 5) {
        int64_t M = (L + R) / 2;
        if (F(M) > F(M + 1)) {
            L = M;
        } else {
            R = M + 1;
        }
    }
    for (int64_t i = L + 1; i <= R; ++i) {
        L = (F(L) < F(i) ? L : i);
    }
    cout << F(L);
}
