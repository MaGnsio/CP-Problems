/**
 *    author:  MaGnsi0
 *    created: 11.10.2021 23:52:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n, sum = 0, res = 0;
        cin >> n;
        map<long long, long long> mp;
        for (int i = 0; i < (int)n; ++i) {
            long long x;
            cin >> x;
            mp[n * x]++;
            sum += 2 * x;
        }
        for (auto&[x, y] : mp) {
            if (y == 0) {
                continue;
            }
            if (sum - x == x) {
                res += y * (y - 1) / 2;
            } else {
                res += mp[sum - x] * y;
                mp[sum - x] = y = 0;
            }
        }
        cout << res << "\n";
    }
}
