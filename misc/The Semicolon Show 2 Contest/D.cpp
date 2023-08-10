/**
 *    author:  MaGnsi0
 *    created: 06.08.2023 09:03:10
**/
#include <bits/stdc++.h>

using namespace std;

int64_t sum_odd(int64_t n) {
    return n * n;
}

int64_t sum_even(int64_t n) {
    return n * (n + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, r, k;
        cin >> n >> r >> k;
        if (r & 1) {
            int64_t j = (r + 1) / 2;
            int64_t x = n * (j - 1);
            cout << sum_odd(x + k) - sum_odd(x) << "\n";
        } else {
            int64_t j = r / 2;
            int64_t x = n * j;
            cout << sum_even(x) - sum_even(x - k) << "\n";
        }
    }
}
