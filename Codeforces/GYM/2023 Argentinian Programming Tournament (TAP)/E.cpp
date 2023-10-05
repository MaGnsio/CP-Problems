/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 11:01:40
**/
#include <bits/stdc++.h>

using namespace std;

int64_t F(int64_t x, int64_t d, int64_t sum) {
    int64_t low = 2, high = 1e6;
    while (low <= high) {
        int64_t mid = (low + high) / 2;
        __int128 sum_ = __int128(mid * x) + (mid * (mid - 1) / 2) * d;
        if (sum_ == sum) {
            return mid;
        }
        if (sum_ < sum) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t A, S, L, R;
    cin >> A >> S >> L >> R;
    int64_t ans = A == S;
    for (int64_t x = L; x < A; ++x) {
        int64_t D = A - x;
        vector<int64_t> ds;
        for (int64_t d = 1; d * d <= D; ++d) {
            if (D % d == 0) {
                ds.push_back(d);
                if (D != d * d) {
                    ds.push_back(D / d);
                }
            }
        }
        for (int64_t d : ds) {
            int64_t n = F(x, d, S);
            int64_t l = x + (n - 1) * d;
            ans += (n > 1 && A <= l && l <= R);
        }
    }
    for (int64_t d = 1; d <= R - A; ++d) {
        int64_t n = F(A, d, S);
        int64_t l = A + (n - 1) * d;
        ans += (n > 1 && A <= l && l <= R);
    }
    cout << ans;
}
