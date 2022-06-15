/**
 *    author:  MaGnsi0
 *    created: 29.04.2022 14:11:28
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> P(N, 0);
    for (int i = 2; i < N; ++i) {
        if (P[i] == 0) {
            for (int j = i; j < N; j += i) {
                P[j]++;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int c, d, x;
        cin >> c >> d >> x;
        int64_t ans = 0;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i != 0) {
                continue;
            }
            int lhs = x / i + d;
            if (lhs % c == 0) {
                ans += 1LL << P[lhs / c];
            }
            if (x == i * i) {
                continue;
            }
            lhs = x / (x / i) + d;
            if (lhs % c == 0) {
                ans += 1LL << P[lhs / c];
            }
        }
        cout << ans << "\n";
    }
}
