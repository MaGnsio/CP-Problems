/**
 *    author:  MaGnsi0
 *    created: 31.01.2024 21:33:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        vector<int64_t> divisors;
        for (int64_t d = 1; d * d <= n; ++d) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (n != d * d) {
                    divisors.push_back(n / d);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        int64_t can = 0;
        for (int64_t d : divisors) {
            if (can > n) { break; }
            int64_t low = d;
            int64_t high = d + can;
            if (low > can + 1) { continue; }
            can = high;
        }
        cout << (can >= n ? "Yes" : "No") << "\n";
    }
}
